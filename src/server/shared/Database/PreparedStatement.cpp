////////////////////////////////////////////////////////////////////////////////
//
//  MILLENIUM-STUDIO
//  Copyright 2016 Millenium-studio SARL
//  All Rights Reserved.
//
////////////////////////////////////////////////////////////////////////////////

#include "PreparedStatement.h"
#include "MySQLConnection.h"
#include "Log.h"

PreparedStatement::PreparedStatement(uint32 index) :
m_stmt(NULL),
m_index(index)
{
}

PreparedStatement::~PreparedStatement()
{
    for (uint32 i = 0; i < statement_data.size(); i++)
    {
        if (statement_data[i].type == TYPE_STRING && statement_data[i].data.str.ptr)
        {
            delete[] statement_data[i].data.str.ptr;
            statement_data[i].data.str.ptr = NULL;
        }
    }
}

void PreparedStatement::BindParameters()
{
    ASSERT (m_stmt);

    uint32 i = 0;
    for (; i < statement_data.size(); i++)
    {
        switch (statement_data[i].type)
        {
            case TYPE_BOOL:
                m_stmt->setBool(i, statement_data[i].data.boolean);
                break;
            case TYPE_UI8:
                m_stmt->setUInt8(i, statement_data[i].data.ui8);
                break;
            case TYPE_UI16:
                m_stmt->setUInt16(i, statement_data[i].data.ui16);
                break;
            case TYPE_UI32:
                m_stmt->setUInt32(i, statement_data[i].data.ui32);
                break;
            case TYPE_I8:
                m_stmt->setInt8(i, statement_data[i].data.i8);
                break;
            case TYPE_I16:
                m_stmt->setInt16(i, statement_data[i].data.i16);
                break;
            case TYPE_I32:
                m_stmt->setInt32(i, statement_data[i].data.i32);
                break;
            case TYPE_UI64:
                m_stmt->setUInt64(i, statement_data[i].data.ui64);
                break;
            case TYPE_I64:
                m_stmt->setInt64(i, statement_data[i].data.i64);
                break;
            case TYPE_FLOAT:
                m_stmt->setFloat(i, statement_data[i].data.f);
                break;
            case TYPE_DOUBLE:
                m_stmt->setDouble(i, statement_data[i].data.d);
                break;
            case TYPE_STRING:
                if (!statement_data[i].data.str.ptr)
                    ASSERT(statement_data[i].data.str.ptr != NULL);
                m_stmt->setString(i, statement_data[i].data.str.ptr, statement_data[i].data.str.len);
                statement_data[i].data.str.ptr = NULL;
                break;
            case TYPE_NULL:
                m_stmt->setNull(i);
                break;
        }
    }
    #ifdef _DEBUG
    if (i < m_stmt->m_paramCount)
        sLog->outWarn(LOG_FILTER_SQL, "[WARNING]: BindParameters() for statement %u did not bind all allocated parameters", m_index);
    #endif
}

//- Bind to buffer
void PreparedStatement::setBool(const uint8 index, const bool value)
{
    if (index >= statement_data.size())
        statement_data.resize(index+1);

    statement_data[index].data.boolean = value;
    statement_data[index].type = TYPE_BOOL;
}

void PreparedStatement::setUInt8(const uint8 index, const uint8 value)
{
    if (index >= statement_data.size())
        statement_data.resize(index+1);

    statement_data[index].data.ui8 = value;
    statement_data[index].type = TYPE_UI8;
}

void PreparedStatement::setUInt16(const uint8 index, const uint16 value)
{
    if (index >= statement_data.size())
        statement_data.resize(index+1);

    statement_data[index].data.ui16 = value;
    statement_data[index].type = TYPE_UI16;
}

void PreparedStatement::setUInt32(const uint8 index, const uint32 value)
{
    if (index >= statement_data.size())
        statement_data.resize(index+1);

    statement_data[index].data.ui32 = value;
    statement_data[index].type = TYPE_UI32;
}

void PreparedStatement::setUInt64(const uint8 index, const uint64 value)
{
    if (index >= statement_data.size())
        statement_data.resize(index+1);

    statement_data[index].data.ui64 = value;
    statement_data[index].type = TYPE_UI64;
}

void PreparedStatement::setInt8(const uint8 index, const int8 value)
{
    if (index >= statement_data.size())
        statement_data.resize(index+1);

    statement_data[index].data.i8 = value;
    statement_data[index].type = TYPE_I8;
}

void PreparedStatement::setInt16(const uint8 index, const int16 value)
{
    if (index >= statement_data.size())
        statement_data.resize(index+1);

    statement_data[index].data.i16 = value;
    statement_data[index].type = TYPE_I16;
}

void PreparedStatement::setInt32(const uint8 index, const int32 value)
{
    if (index >= statement_data.size())
        statement_data.resize(index+1);

    statement_data[index].data.i32 = value;
    statement_data[index].type = TYPE_I32;
}

void PreparedStatement::setInt64(const uint8 index, const int64 value)
{
    if (index >= statement_data.size())
        statement_data.resize(index+1);

    statement_data[index].data.i64 = value;
    statement_data[index].type = TYPE_I64;
}

void PreparedStatement::setFloat(const uint8 index, const float value)
{
    if (index >= statement_data.size())
        statement_data.resize(index+1);

    statement_data[index].data.f = value;
    statement_data[index].type = TYPE_FLOAT;
}

void PreparedStatement::setDouble(const uint8 index, const double value)
{
    if (index >= statement_data.size())
        statement_data.resize(index+1);

    statement_data[index].data.d = value;
    statement_data[index].type = TYPE_DOUBLE;
}

void PreparedStatement::setString(const uint8 index, const std::string& value)
{
    if (index >= statement_data.size())
        statement_data.resize(index+1);

    size_t len = value.size();
    const char* src = value.c_str();

    char* data = new char[len];
    for (size_t i = 0; i < len; ++i)
        data[i] = src[i];

    statement_data[index].data.str.ptr = data;
    statement_data[index].data.str.len = len;
    statement_data[index].type = TYPE_STRING;
}

void PreparedStatement::setString(const uint8 index, const nullable_string& value)
{
    if (index >= statement_data.size())
        statement_data.resize(index+1);

    if (value.length)
        return setString(index, value.ptr, value.length);

    statement_data[index].type = TYPE_NULL;
}

void PreparedStatement::setString(const uint8 index, const char* value)
{
    if (index >= statement_data.size())
        statement_data.resize(index+1);

    ASSERT(value != NULL);
    size_t len = strlen(value);

    char* data = new char[len];
    for (size_t i = 0; i < len; ++i)
        data[i] = value[i];

    statement_data[index].data.str.ptr = data;
    statement_data[index].data.str.len = len;
    statement_data[index].type = TYPE_STRING;
}

void PreparedStatement::setString(const uint8 index, const char* value, uint32 len)
{
    if (index >= statement_data.size())
        statement_data.resize(index+1);

    ASSERT(value != NULL);

    char* data = new char[len];
    for (size_t i = 0; i < len; ++i)
        data[i] = value[i];

    statement_data[index].data.str.ptr = data;
    statement_data[index].data.str.len = len;
    statement_data[index].type = TYPE_STRING;
}

MySQLPreparedStatement::MySQLPreparedStatement(MYSQL_STMT* stmt) :
m_stmt(NULL),
m_Mstmt(stmt),
m_bind(NULL)
{
    /// Initialize variable parameters
    m_paramCount = mysql_stmt_param_count(stmt);
    m_paramsSet.assign(m_paramCount, false);
    m_bind = new MYSQL_BIND[m_paramCount];
    memset(m_bind, 0, sizeof(MYSQL_BIND)*m_paramCount);

    /// "If set to 1, causes mysql_stmt_store_result() to update the metadata MYSQL_FIELD->max_length value."
    bool bool_tmp = 1;
    mysql_stmt_attr_set(stmt, STMT_ATTR_UPDATE_MAX_LENGTH, &bool_tmp);
}

MySQLPreparedStatement::~MySQLPreparedStatement()
{
    ClearParameters();
    if (m_Mstmt->bind_result_done)
    {
        delete[] m_Mstmt->bind->length;
        delete[] m_Mstmt->bind->is_null;
    }
    mysql_stmt_close(m_Mstmt);
    delete[] m_bind;
}

void MySQLPreparedStatement::ClearParameters()
{
    for (uint32 i=0; i < m_paramCount; ++i)
    {
        delete[] (char*) m_bind[i].buffer;
        m_bind[i].buffer = NULL;
        m_paramsSet[i] = false;
    }
}

//- Bind on mysql level
bool MySQLPreparedStatement::CheckValidIndex(uint8 index)
{
    if (index >= m_paramCount)
    {
        sLog->outError(LogFilterType::LOG_FILTER_SQL, "Invalid index %u for prepared statement %u", index, m_stmt->m_index);
        ASSERT(false);
    }

    if (m_paramsSet[index])
    {
        sLog->outWarn(LOG_FILTER_SQL, "[WARNING] Prepared Statement (id: %u) trying to bind value on already bound index (%u).", m_stmt->m_index, index);
        ASSERT(false);
    }
    return true;
}

void MySQLPreparedStatement::setBool(const uint8 index, const bool value)
{
    setUInt8(index, value ? 1 : 0);
}

void MySQLPreparedStatement::setUInt8(const uint8 index, const uint8 value)
{
    CheckValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    setValue(param, MYSQL_TYPE_TINY, &value, sizeof(uint8), true);
}

void MySQLPreparedStatement::setUInt16(const uint8 index, const uint16 value)
{
    CheckValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    setValue(param, MYSQL_TYPE_SHORT, &value, sizeof(uint16), true);
}

void MySQLPreparedStatement::setUInt32(const uint8 index, const uint32 value)
{
    CheckValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    setValue(param, MYSQL_TYPE_LONG, &value, sizeof(uint32), true);
}

void MySQLPreparedStatement::setUInt64(const uint8 index, const uint64 value)
{
    CheckValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    setValue(param, MYSQL_TYPE_LONGLONG, &value, sizeof(uint64), true);
}

void MySQLPreparedStatement::setInt8(const uint8 index, const int8 value)
{
    CheckValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    setValue(param, MYSQL_TYPE_TINY, &value, sizeof(int8), false);
}

void MySQLPreparedStatement::setInt16(const uint8 index, const int16 value)
{
    CheckValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    setValue(param, MYSQL_TYPE_SHORT, &value, sizeof(int16), false);
}

void MySQLPreparedStatement::setInt32(const uint8 index, const int32 value)
{
    CheckValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    setValue(param, MYSQL_TYPE_LONG, &value, sizeof(int32), false);
}

void MySQLPreparedStatement::setInt64(const uint8 index, const int64 value)
{
    CheckValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    setValue(param, MYSQL_TYPE_LONGLONG, &value, sizeof(int64), false);
}

void MySQLPreparedStatement::setFloat(const uint8 index, const float value)
{
    CheckValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    setValue(param, MYSQL_TYPE_FLOAT, &value, sizeof(float), (value > 0.0f));
}

void MySQLPreparedStatement::setDouble(const uint8 index, const double value)
{
    CheckValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    setValue(param, MYSQL_TYPE_DOUBLE, &value, sizeof(double), (value > 0.0f));
}

void MySQLPreparedStatement::setString(const uint8 index, char* value)
{
    ASSERT(value != NULL);

    return setString(index, value, strlen(value));
}

void MySQLPreparedStatement::setString(const uint8 index, char* value, uint32 len)
{
    CheckValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    
    ASSERT(value != NULL);

    param->buffer_type = MYSQL_TYPE_VAR_STRING;
    delete [] static_cast<char *>(param->buffer);
    param->buffer = value;
    param->buffer_length = len;
    param->is_null_value = 0;
    param->length_value = len;
}

void MySQLPreparedStatement::setNull(const uint8 index)
{
    CheckValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];

    param->buffer_type = MYSQL_TYPE_NULL;
    delete [] static_cast<char *>(param->buffer);
    param->buffer = NULL;
    param->buffer_length = 0;
    param->is_null_value = 1;
    param->length_value = 0;
}

void MySQLPreparedStatement::setValue(MYSQL_BIND* param, enum_field_types type, const void* value, uint32 len, bool isUnsigned)
{
    param->buffer_type = type;
    delete [] static_cast<char *>(param->buffer);
    param->buffer = new char[len];
    param->buffer_length = 0;
    param->is_null_value = 0;
    param->length_value = 0;               // Only != NULL for strings
    param->is_unsigned = isUnsigned;

    memcpy(param->buffer, value, len);
}

std::string MySQLPreparedStatement::getQueryString(const char *query)
{
    std::ostringstream ss;

    uint32 i = 0;
    char const* pchr;
    while ((pchr = strchr(query, '?'))) // double-parentheses to prevent GCC warning
    {
        ss << std::string(query, pchr - query);

        if (i < m_stmt->statement_data.size())
        {
            switch (m_stmt->statement_data[i].type)
            {
                case TYPE_BOOL:
                    ss << (m_stmt->statement_data[i].data.boolean ? '1' : '0');
                    break;
                case TYPE_UI8:
                    ss << uint16(m_stmt->statement_data[i].data.ui8);  // stringstream will append a character with that code instead of numeric representation
                    break;
                case TYPE_UI16:
                    ss << m_stmt->statement_data[i].data.ui16;
                    break;
                case TYPE_UI32:
                    ss << m_stmt->statement_data[i].data.ui32;
                    break;
                case TYPE_I8:
                    ss << int16(m_stmt->statement_data[i].data.i8);  // stringstream will append a character with that code instead of numeric representation
                    break;
                case TYPE_I16:
                    ss << m_stmt->statement_data[i].data.i16;
                    break;
                case TYPE_I32:
                    ss << m_stmt->statement_data[i].data.i32;
                    break;
                case TYPE_UI64:
                    ss << m_stmt->statement_data[i].data.ui64;
                    break;
                case TYPE_I64:
                    ss << m_stmt->statement_data[i].data.i64;
                    break;
                case TYPE_FLOAT:
                    ss << m_stmt->statement_data[i].data.f;
                    break;
                case TYPE_DOUBLE:
                    ss << m_stmt->statement_data[i].data.d;
                    break;
                case TYPE_STRING:
                    if (m_stmt->statement_data[i].data.str.ptr)
                    {
                        ss
                            << '"'
                            << std::string(m_stmt->statement_data[i].data.str.ptr, m_stmt->statement_data[i].data.str.len)
                            << '"';
                    }
                    else
                        ss << "<STRING MOVED>";
                    break;
                case TYPE_NULL:
                    ss << "NULL";
                    break;
                default:
                    ss << "<BAD TYPE " << uint32(m_stmt->statement_data[i].type) << ">";
                    break;
            }
        }
        else
        {
            ss << "<BAD IDX " << i << ">";
        }

        ++i;
        query = pchr + 1;
    }

    ss << query;

    return ss.str();
}

//- Execution
PreparedStatementTask::PreparedStatementTask(PreparedStatement* stmt) :
m_stmt(stmt),
m_has_result(false)
{
}

PreparedStatementTask::PreparedStatementTask(PreparedStatement* stmt, PreparedQueryResultFuture result) :
m_stmt(stmt),
m_has_result(true),
m_result(result)
{
}


PreparedStatementTask::~PreparedStatementTask()
{
    delete m_stmt;
}

bool PreparedStatementTask::Execute()
{
    if (m_has_result)
    {
        PreparedResultSet* result = m_conn->Query(m_stmt);
        if (!result || !result->GetRowCount())
        {
            delete result;
            m_result.set(PreparedQueryResult(NULL));
            return false;
        }
        m_result.set(PreparedQueryResult(result));
        return true;
    }

    return m_conn->Execute(m_stmt);
}
