////////////////////////////////////////////////////////////////////////////////
//
//  MILLENIUM-STUDIO
//  Copyright 2016 Millenium-studio SARL
//  All Rights Reserved.
//
////////////////////////////////////////////////////////////////////////////////

/// \addtogroup u2w
/// @{
/// \file

#ifndef _OPCODES_H
#define _OPCODES_H

#include "Common.h"

enum OpcodeTransferDirection : uint8
{
    WOW_SERVER_TO_CLIENT = 0,
    WOW_CLIENT_TO_SERVER = 1,

    TRANSFER_DIRECTION_MAX = 2
};

/// List of Opcodes
enum Opcodes
{
    MAX_OPCODE                                        = (0x3FFF),
    NUM_OPCODE_HANDLERS                               = MAX_OPCODE + 1,
    UNKNOWN_OPCODE                                    = (0xFFFF+1),
    NULL_OPCODE                                       = 0,
    COMPRESSED_OPCODE_MASK                            = 0x8000,

    //////////////////////////////////////////////////////////////////////////
    /// Jam Client Protocol
    //////////////////////////////////////////////////////////////////////////
    #pragma region JamProtocol
        /// Opcodes
        SMSG_AUTH_CHALLENGE                         = 0x2FC6, ///< 6.2.3 20726
    #pragma endregion

    //////////////////////////////////////////////////////////////////////////
    /// Jam Client Dispatch
    //////////////////////////////////////////////////////////////////////////
    #pragma region JamDispatch
        /// Base opcodes
        SMSG_AUTH_RESPONSE                          = 0x24EA, ///< 6.2.3 20726
        SMSG_CACHE_VERSION                          = 0x26C4, ///< 6.2.3 20726
        SMSG_ADDON_INFO                             = 0x26FC, ///< 6.2.3 20726
        SMSG_FEATURE_SYSTEM_STATUS                  = 0x2557, ///< 6.2.3 20726
        SMSG_SET_TIME_ZONE_INFORMATION              = 0x2620, ///< 6.2.3 20726
        SMSG_LOGIN_VERIFY_WORLD                     = 0x2532, ///< 6.2.3 20726
        SMSG_NEW_WORLD                              = 0x2531, ///< 6.2.3 20726
        SMSG_LOGIN_SET_TIME_SPEED                   = 0x26CD, ///< 6.2.3 20726
        SMSG_HOTFIX_NOTIFY_BLOB                     = 0x252A, ///< 6.2.3 20726
        SMSG_HOTFIX_NOTIFY                          = 0x2529, ///< 6.2.3 20726
        SMSG_WORLD_SERVER_INFO                      = 0x2548, ///< 6.2.3 20726
        SMSG_INITIAL_SETUP                          = 0x24FD, ///< 6.2.3 20726
        SMSG_PONG                                   = 0x2FCB, ///< 6.2.3 20726
        SMSG_UITIME                                 = 0x1B4C, ///< 6.2.3 20726

        /// Query
        SMSG_DB_REPLY                               = 0x2528, ///< 6.2.3 20726
        SMSG_QUERY_CREATURE_RESPONSE                = 0x267D, ///< 6.2.3 20726
        SMSG_NPC_TEXT_UPDATE                        = 0x02F7, ///< 6.2.3 20726
        SMSG_NAME_QUERY_RESPONSE                    = 0x17D0, ///< 6.2.3 20726
        SMSG_REALM_QUERY_RESPONSE                   = 0x2668, ///< 6.2.3 20726
        SMSG_GAMEOBJECT_QUERY_RESPONSE              = 0x03EB, ///< 6.2.3 20726
        SMSG_QUERY_TIME_RESPONSE                    = 0x269C, ///< 6.2.3 20726

        /// Misc
        SMSG_DISPLAY_GAME_ERROR                     = 0x253B, ///< 6.2.3 20726
        SMSG_UPDATE_ACTION_BUTTONS                  = 0x2579, ///< 6.2.3 20726
        SMSG_SET_PROFICIENCY                        = 0x26F4, ///< 6.2.3 20726
        SMSG_INIT_WORLD_STATES                      = 0x2709, ///< 6.2.3 20726
        SMSG_UPDATE_WORLD_STATE                     = 0x270A, ///< 6.2.3 20726
        SMSG_EMOTE                                  = 0x277B, ///< 6.2.3 20726
        SMSG_EXPLORATION_EXPERIENCE                 = 0x2720, ///< 6.2.3 20726
        SMSG_LOG_XP_GAIN                            = 0x269D, ///< 6.2.3 20726
        SMSG_LEVELUP_INFO                           = 0x1643, ///< 6.2.3 20726
        SMSG_ITEM_PUSH_RESULT                       = 0x25BA, ///< 6.2.3 20726
        SMSG_INIT_CURRENCY                          = 0x0F48, ///< 6.2.3 20726
        SMSG_UPDATE_CURRENCY                        = 0x0BFC, ///< 6.2.3 20726
        SMSG_UPDATE_CURRENCY_WEEK_LIMIT             = 0x0F63, ///< 6.2.3 20726
        SMSG_WEEKLY_RESET_CURRENCY                  = 0x0EF0, ///< 6.2.3 20726
        SMSG_EQUIPMENT_SET_LIST                     = 0x0360, ///< 6.2.3 20726
        SMSG_BINDER_CONFIRM                         = 0x26BB, ///< 6.2.3 20726
        SMSG_BIND_POINT_UPDATE                      = 0x24FA, ///< 6.2.3 20726
        SMSG_UPDATE_TALENT_DATA                     = 0x256E, ///< 6.2.3 20726
        SMSG_TRANSFER_ABORTED                       = 0x26C2, ///< 6.2.3 20726
        SMSG_TRANSFER_PENDING                       = 0x2569, ///< 6.2.3 20726
        SMSG_INVENTORY_CHANGE_FAILURE               = 0x26E2, ///< 6.2.3 20726
        SMSG_SET_DUNGEON_DIFFICULTY                 = 0x264F, ///< 6.2.3 20726
        SMSG_SET_RAID_DIFFICULTY                    = 0x1368, ///< 6.2.3 20726
        SMSG_LOAD_CUF_PROFILES                      = 0x2553, ///< 6.2.3 20726
        SMSG_STANDSTATE_UPDATE                      = 0x12E0, ///< 6.2.3 20726
        SMSG_START_TIMER                            = 0x2541, ///< 6.2.3 20726
        SMSG_START_ELAPSED_TIMER                    = 0x259D, ///< 6.2.3 20726
        SMSG_START_ELAPSED_TIMERS                   = 0x259F, ///< 6.2.3 20726
        SMSG_STOP_ELAPSED_TIMER                     = 0x259E, ///< 6.2.3 20726
        SMSG_DEATH_RELEASE_LOC                      = 0x2687, ///< 6.2.3 20726
        SMSG_CORPSE_RECLAIM_DELAY                   = 0x270C, ///< 6.2.3 20726
        SMSG_CORPSE_LOCATION                        = 0x25EC, ///< 6.2.3 20726
        SMSG_CORPSE_TRANSPORT_QUERY                 = 0x26D2, ///< 6.2.3 20726
        SMSG_DURABILITY_DAMAGE_DEATH                = 0x2708, ///< 6.2.3 20726
        SMSG_PLAY_MUSIC                             = 0x2728, ///< 6.2.3 20726
        SMSG_PLAY_OBJECT_SOUND                      = 0x2729, ///< 6.2.3 20726
        SMSG_PLAY_SOUND                             = 0x2727, ///< 6.2.3 20726
        SMSG_DISPLAY_TOAST                          = 0x25BB, ///< 6.2.3 20726
        SMSG_ITEM_ENCHANT_TIME_UPDATE               = 0x2715, ///< 6.2.3 20726
        SMSG_ENCHANTMENT_LOG                        = 0x26D3, ///< 6.2.3 20726
        SMSG_PARTY_KILL_LOG                         = 0x271B, ///< 6.2.3 20726
        SMSG_PROCRESIST                             = 0x1677, ///< 6.2.3 20726
        SMSG_CLEAR_TARGET                           = 0x265D, ///< 6.2.3 20726
        SMSG_WEATHER                                = 0x2651, ///< 6.2.3 20726
        SMSG_SET_PHASE_SHIFT                        = 0x137C, ///< 6.2.3 20726
        SMSG_TRIGGER_CINEMATIC                      = 0x277C, ///< 6.2.3 20726
        SMSG_TOTEM_CREATED                          = 0x2675, ///< 6.2.3 20726
        SMSG_RESPEC_WIPE_CONFIRM                    = 0x25A8, ///< 6.2.3 20726
        SMSG_USE_EQUIPMENT_SET_RESULT               = 0x2710, ///< 6.2.3 20726
        SMSG_TRADE_STATUS                           = 0x24FF, ///< 6.2.3 20726
        SMSG_TRADE_UPDATED                          = 0x24FE, ///< 6.2.3 20726
        SMSG_SHOW_NEUTRAL_PLAYER_FACTION_SELECT_UI  = 0x2574, ///< 6.2.3 20726
        SMSG_NEUTRAL_PLAYER_FACTION_SELECT_RESULT   = 0x2575, ///< (unused)
        SMSG_INSPECT_TALENT                         = 0x0F7B, ///< 6.2.3 20726
        SMSG_INSPECT_HONOR_STATS                    = 0x2538, ///< 6.2.3 20726
        SMSG_INSPECT_RATED_BG_STATS                 = 0x065F, ///< 6.2.3 20726
        SMSG_TIME_SYNC_REQUEST                      = 0x2D1E, ///< 6.2.3 20726
        SMSG_RESUME_TOKEN                           = 0x2544, ///< 6.2.3 20726
        SMSG_BARBER_SHOP_RESULT                     = 0x266B, ///< 6.2.3 20726
        SMSG_ENABLE_BARBER_SHOP                     = 0x266A, ///< 6.2.3 20726
        SMSG_PAGE_TEXT_QUERY_RESPONSE               = 0x1B58, ///< 6.2.3 20726
        SMSG_PAGE_TEXT                              = 0x26D8, ///< 6.2.3 20726
        SMSG_READ_ITEM_FAILED                       = 0x0ED3, ///< 6.2.3 20726
        SMSG_READ_ITEM_OK                           = 0x0AF7, ///< 6.2.3 20726
        SMSG_TEXT_EMOTE                             = 0x2624, ///< 6.2.3 20726
        SMSG_TITLE_EARNED                           = 0x268C, ///< 6.2.3 20726
        SMSG_TITLE_LOST                             = 0x268D, ///< 6.2.3 20726
        SMSG_WHOIS                                  = 0x0FD4, ///< 6.2.3 20726
        SMSG_TRIGGER_MOVIE                          = 0x2677, ///< 6.2.3 20726
        SMSG_UPDATE_LAST_INSTANCE                   = 0x2632, ///< 6.2.3 20726
        SMSG_UPDATE_INSTANCE_OWNERSHIP              = 0x2652, ///< 6.2.3 20726
        SMSG_SUMMON_REQUEST                         = 0x26DF, ///< 6.2.3 20726
        SMSG_STOP_MIRROR_TIMER                      = 0x26D1, ///< 6.2.3 20726
        SMSG_START_MIRROR_TIMER                     = 0x26CF, ///< 6.2.3 20726
        SMSG_SOCKET_GEMS                            = 0x26E7, ///< 6.2.3 20726
        SMSG_RESURRECT_REQUEST                      = 0x24FC, ///< 6.2.3 20726
        SMSG_RESPOND_INSPECT_ACHIEVEMENTS           = 0x24EF, ///< 6.2.3 20726
        SMSG_RESET_FAILED_NOTIFY                    = 0x2663, ///< 6.2.3 20726
        SMSG_SETUP_RESEARCH_HISTORY                 = 0x2502, ///< 6.2.3 20726
        SMSG_RESEARCH_COMPLETE                      = 0x2503, ///< 6.2.3 20726
        SMSG_REQUEST_CEMETERY_LIST_RESPONSE         = 0x2525, ///< 6.2.3 20726
        SMSG_PLAYED_TIME                            = 0x268A, ///< 6.2.3 20726
        SMSG_BREAK_TARGET                           = 0x25ED, ///< 6.2.3 20726
        SMSG_CANCEL_AUTO_REPEAT                     = 0x2694, ///< 6.2.3 20726
        SMSG_CANCEL_COMBAT                          = 0x26B3, ///< 6.2.3 20726
        SMSG_COMPLAIN_RESULT                        = 0x0F80, ///< 6.2.3 20726
        SMSG_XPGAIN_ABORTED                         = 0x1300, ///< 6.2.3 20726
        SMSG_SUPERCEDED_SPELL                       = 0x04F4, ///< 6.2.3 20726
        SMSG_PVP_CREDIT                             = 0x2698, ///< 6.2.3 20726
        SMSG_PRE_RESURRECT                          = 0x0C00, ///< 6.2.3 20726
        SMSG_PLAY_ONE_SHOT_ANIM_KIT                 = 0x26F0, ///< 6.2.3 20726
        SMSG_SET_AI_ANIM_KIT                        = 0x26EF, ///< 6.2.3 20726
        SMSG_SET_MELEE_ANIM_KIT                     = 0x26F2, ///< 6.2.3 20726
        SMSG_SET_ANIM_TIER                          = 0x26F3, ///< 6.2.3 20726
        SMSG_SET_PLAY_HOVER_ANIM                    = 0x2551, ///< 6.2.3 20726
        SMSG_SET_MOVEMENT_ANIM_KIT                  = 0x26F1, ///< 6.2.3 20726
        SMSG_PLAYER_BOUND                           = 0x24FB, ///< 6.2.3 20726
        SMSG_OVERRIDE_LIGHT                         = 0x2669, ///< 6.2.3 20726
        SMSG_PRINT_NOTIFICATION                     = 0x2566, ///< 6.2.3 20726
        SMSG_SPECIAL_MOUNT_ANIM                     = 0x2649, ///< 6.2.3 20726
        SMSG_ITEM_TIME_UPDATE                       = 0x2714, ///< 6.2.3 20726
        SMSG_QUERY_ITEM_TEXT_RESPONSE               = 0x2778, ///< 6.2.3 20726
        SMSG_ITEM_PURCHASE_REFUND_RESULT            = 0x2535, ///< 6.2.3 20726
        SMSG_GAMEOBJECT_DESPAWN                     = 0x137F, ///< 6.2.3 20726
        SMSG_GAMEOBJECT_CUSTOM_ANIM                 = 0x1ACC, ///< 6.2.3 20726
        SMSG_GAME_OBJECT_ACTIVATE_ANIM_KIT          = 0x255B, ///< 6.2.3 20726
        SMSG_FISH_NOT_HOOKED                        = 0x267B, ///< 6.2.3 20726
        SMSG_FISH_ESCAPED                           = 0x267C, ///< 6.2.3 20726
        SMSG_DESTRUCTIBLE_BUILDING_DAMAGE           = 0x26B4, ///< 6.2.3 20726
        SMSG_CROSSED_INEBRIATION_THRESHOLD          = 0x266F, ///< 6.2.3 20726
        SMSG_CLIENT_CONTROL_UPDATE                  = 0x07D0, ///< 6.2.3 20726
        SMSG_AREA_TRIGGER_NO_CORPSE                 = 0x26D6, ///< 6.2.3 20726
        SMSG_BAG_SORT_RESULT                        = 0x0BF3, ///< 6.2.3 20726
        SMSG_VIGNETTE_UPDATE                        = 0x272D, ///< 6.2.3 20726
        SMSG_ACCOUNT_MOUNT_UPDATE                   = 0x2549, ///< 6.2.3 20726
        SMSG_PLAY_SCENE                             = 0x25D3, ///< 6.2.3 20726
        SMSG_CANCEL_SCENE                           = 0x25D4, ///< 6.2.3 20726
        SMSG_TALENTS_INVOLUNTARILY_RESET            = 0x26D7, ///< 6.2.3 20726
        SMSG_SET_ITEM_PURCHASE_DATA                 = 0x2536, ///< 6.2.3 20726
        SMSG_SHOW_TRADE_SKILL_RESPONSE              = 0x272F, ///< 6.2.3 20726
        SMSG_FORCED_DEATH_UPDATE                    = 0x2688, ///< 6.2.3 20779

        /// Control Alert
        SMSG_LOSS_OF_CONTROL_AURA_UPDATE            = 0x2616, ///< 6.2.3 20726
        SMSG_ADD_LOSS_OF_CONTROL                    = 0x2617, ///< 6.2.3 20726
        SMSG_CLEAR_LOSS_OF_CONTROL                  = 0x2619, ///< 6.2.3 20726
        SMSG_REMOVE_LOSS_OF_CONTROL                 = 0x2618, ///< 6.2.3 20726

        /// Reputations
        SMSG_INITIALIZE_FACTIONS                    = 0x26E4, ///< 6.2.3 20726
        SMSG_FACTION_BONUS_INFO                     = 0x26E5, ///< 6.2.3 20726
        SMSG_SET_FACTION_VISIBLE                    = 0x26E9, ///< 6.2.3 20726
        SMSG_SET_FACTION_NOT_VISIBLE                = 0x26EA, ///< 6.2.3 20726
        SMSG_SET_FACTION_STANDING                   = 0x26EB, ///< 6.2.3 20726
        SMSG_SET_FACTION_ATWAR                      = 0x02F4, ///< 6.2.3 20726
        SMSG_SET_FORCED_REACTIONS                   = 0x26DB, ///< 6.2.3 20726

        /// Interaction
        SMSG_LOGOUT_RESPONSE                        = 0x262D, ///< 6.2.3 20726
        SMSG_LOGOUT_CANCEL_ACK                      = 0x262F, ///< 6.2.3 20726
        SMSG_LOGOUT_COMPLETE                        = 0x262E, ///< 6.2.3 20726
        SMSG_GOSSIP_POI                             = 0x2752, ///< 6.2.3 20726
        SMSG_ARCHAEOLOGY_SURVERY_CAST               = 0x2504, ///< 6.2.3 20726

        /// World Object management
        SMSG_UPDATE_OBJECT                          = 0x277D, ///< 6.2.3 20726
        SMSG_POWER_UPDATE                           = 0x2680, ///< 6.2.3 20726
        SMSG_ADJUST_SPLINE_DURATION                 = 0x256C, ///< 6.2.3 20726

        /// Character list
        SMSG_ENUM_CHARACTERS_RESULT                 = 0x2500, ///< 6.2.3 20726
        SMSG_CREATE_CHAR                            = 0x26C0, ///< 6.2.3 20726
        SMSG_CHAR_DELETE                            = 0x13DF, ///< 6.2.3 20726
        SMSG_SET_PLAYER_DECLINED_NAMES_RESULT       = 0x2689, ///< 6.2.3 20726
        SMSG_CHAR_FACTION_CHANGE                    = 0x0EF8, ///< 6.2.3 20726
        SMSG_CHAR_RENAME                            = 0x0264, ///< 6.2.3 20726
        SMSG_CHAR_CUSTOMIZE_RESULT                  = 0x1B6B, ///< 6.2.3 20726
        SMSG_CHAR_CUSTOMIZE                         = 0x269B, ///< 6.2.3 20726
        SMSG_GENERATE_RANDOM_CHARACTER_NAME_RESULT  = 0x2501, ///< 6.2.3 20726

        /// Account data
        SMSG_ACCOUNT_DATA_TIMES                     = 0x26CA, ///< 6.2.3 20726
        SMSG_UPDATE_ACCOUNT_DATA                    = 0x26C9, ///< 6.2.3 20726
        SMSG_TUTORIAL_FLAGS                         = 0x2770, ///< 6.2.3 20726

        /// Combat
        SMSG_ATTACKER_STATE_UPDATE                  = 0x2749, ///< 6.2.3 20726
        SMSG_ATTACK_START                           = 0x25EE, ///< 6.2.3 20726
        SMSG_ATTACK_STOP                            = 0x25EF, ///< 6.2.3 20726
        SMSG_AI_REACTION                            = 0x2661, ///< 6.2.3 20726
        SMSG_ATTACK_SWING_ERROR                     = 0x26B5, ///< 6.2.3 20726

        /// Duel
        SMSG_DUEL_REQUESTED                         = 0x25F1, ///< 6.2.3 20726
        SMSG_DUEL_COUNTDOWN                         = 0x25F4, ///< 6.2.3 20726
        SMSG_DUEL_COMPLETE                          = 0x25F5, ///< 6.2.3 20726
        SMSG_DUEL_INBOUNDS                          = 0x0AF4, ///< 6.2.3 20726
        SMSG_DUEL_OUT_OF_BOUNDS                     = 0x25F2, ///< 6.2.3 20726
        SMSG_DUEL_WINNER                            = 0x25F6, ///< 6.2.3 20726
        SMSG_CAN_DUEL_RESULT                        = 0x25F7, ///< 6.2.3 20726

        /// Vendor
        SMSG_LIST_INVENTORY                         = 0x0E5B, ///< 6.2.3 20726
        SMSG_BUY_FAILED                             = 0x2674, ///< 6.2.3 20726
        SMSG_BUY_ITEM                               = 0x0357, ///< 6.2.3 20726
        SMSG_SELL_ITEM                              = 0x0EE0, ///< 6.2.3 20726

        /// Achievement
        SMSG_ALL_ACHIEVEMENT_DATA                   = 0x24ED, ///< 6.2.3 20726
        SMSG_ACHIEVEMENT_DELETED                    = 0x26A0, ///< 6.2.3 20726
        SMSG_ACHIEVEMENT_EARNED                     = 0x25E0, ///< 6.2.3 20726
        SMSG_ACCOUNT_CRITERIA_UPDATE                = 0x25D2, ///< 6.2.3 20726
        SMSG_ACCOUNT_CRITERIA_UPDATE_ALL            = 0x0A60, ///< 6.2.3 20726
        SMSG_CRITERIA_DELETED                       = 0x269F, ///< 6.2.3 20726
        SMSG_CRITERIA_UPDATE                        = 0x2699, ///< 6.2.3 20726

        /// Friends
        SMSG_CONTACT_LIST                           = 0x2744, ///< 6.2.3 20726
        SMSG_FRIEND_STATUS                          = 0x2745, ///< 6.2.3 20726

        /// Taxi
        SMSG_TAXI_NODE_STATUS                       = 0x2626, ///< 6.2.3 20726
        SMSG_NEW_TAXI_PATH                          = 0x2628, ///< 6.2.3 20726
        SMSG_SHOW_TAXI_NODES                        = 0x2679, ///< 6.2.3 20726
        SMSG_ACTIVATE_TAXI_REPLY                    = 0x2627, ///< 6.2.3 20726

        /// Loot
        SMSG_LOOT_LIST                              = 0x2702, ///< 6.2.3 20726
        SMSG_LOOT_RESPONSE                          = 0x25AA, ///< 6.2.3 20726
        SMSG_LOOT_MONEY_NOTIFY                      = 0x25B2, ///< 6.2.3 20726
        SMSG_LOOT_RELEASE                           = 0x25B1, ///< 6.2.3 20726
        SMSG_LOOT_RELEASE_ALL                       = 0x25B0, ///< 6.2.3 20726
        SMSG_LOOT_REMOVED                           = 0x25AB, ///< 6.2.3 20726
        SMSG_COIN_REMOVED                           = 0x25AD, ///< 6.2.3 20726
        SMSG_LOOT_ALL_PASSED                        = 0x25B8, ///< 6.2.3 20726
        SMSG_LOOT_CONTENTS                          = 0x2573, ///< (unused)
        SMSG_LOOT_ITEM_LIST                         = 0x25B6, ///< (unused)
        SMSG_MASTER_LOOT_CANDIDATE_LIST             = 0x25B5, ///< 6.2.3 20726
        SMSG_LOOT_ROLL                              = 0x25B4, ///< 6.2.3 20726
        SMSG_LOOT_ROLLS_COMPLETE                    = 0x25B7, ///< (unused)
        SMSG_LOOT_ROLL_WON                          = 0x25B9, ///< 6.2.3 20726
        SMSG_LOOT_START_ROLL                        = 0x02CB, ///< 6.2.3 20726
        SMSG_AE_LOOT_TARGETS                        = 0x25AE, ///< (unused)
        SMSG_AE_LOOT_TARGETS_ACK                    = 0x0000, ///< (unused)
        SMSG_ITEM_BONUS_DEBUG                       = 0x17F3, ///< 6.2.3 20726

        /// Bank
        SMSG_SHOW_BANK                              = 0x2629, ///< 6.2.3 20726

        /// Rune
        SMSG_RESYNC_RUNES                           = 0x26BF, ///< 6.2.3 20726
        SMSG_DEBUG_RUNE_REGEN                       = 0x0FD3, ///< 6.2.3 20726
        SMSG_ADD_RUNE_POWER                         = 0x2665, ///< 6.2.3 20726
        SMSG_CONVERT_RUNE                           = 0x2664, ///< 6.2.3 20726

        /// Group
        SMSG_PARTY_UPDATE                           = 0x258E, ///< 6.2.3 20726
        SMSG_PARTY_MEMBER_STATE_FULL                = 0x0EF3, ///< 6.2.3 20726
        SMSG_PARTY_MEMBER_STATE_PARTIAL             = 0x06EF, ///< 6.2.3 20726
        SMSG_PARTY_INVITE                           = 0x2555, ///< 6.2.3 20726
        SMSG_GROUP_DECLINE                          = 0x274D, ///< 6.2.3 20726
        SMSG_PARTY_COMMAND_RESULT                   = 0x2751, ///< 6.2.3 20726
        SMSG_GROUP_UNINVITE                         = 0x274E, ///< 6.2.3 20726
        SMSG_GROUP_NEW_LEADER                       = 0x25CA, ///< 6.2.3 20726
        SMSG_MINIMAP_PING                           = 0x267A, ///< 6.2.3 20726
        SMSG_SET_LOOT_METHOD_FAILED                 = 0x2784, ///< 6.2.3 20726
        SMSG_RANDOM_ROLL                            = 0x25CD, ///< 6.2.3 20726
        SMSG_SEND_RAID_TARGET_UPDATE_SINGLE         = 0x25CC, ///< 6.2.3 20726
        SMSG_SEND_RAID_TARGET_UPDATE_ALL            = 0x25CB, ///< 6.2.3 20726
        SMSG_READY_CHECK_COMPLETED                  = 0x2591, ///< 6.2.3 20726
        SMSG_READY_CHECK_RESPONSE                   = 0x2590, ///< 6.2.3 20726
        SMSG_READY_CHECK_STARTED                    = 0x258F, ///< 6.2.3 20726
        SMSG_ROLL_POLL_INFORM                       = 0x1663, ///< 6.2.3 20726
        SMSG_ROLE_CHANGED_INFORM                    = 0x2509, ///< 6.2.3 20726
        SMSG_GROUP_DESTROYED                        = 0x274F, ///< 6.2.3 20726

        /// Battleground
        SMSG_BATTLEFIELD_STATUS_QUEUED                      = 0x250E, ///< 6.2.3 20726
        SMSG_BATTLEFIELD_STATUS_NONE                        = 0x250F, ///< 6.2.3 20726
        SMSG_BATTLEFIELD_STATUS_NEED_CONFIRMATION           = 0x250C, ///< 6.2.3 20726
        SMSG_BATTLEFIELD_STATUS_ACTIVE                      = 0x250D, ///< 6.2.3 20726
        SMSG_BATTLEFIELD_STATUS_FAILED                      = 0x2510, ///< 6.2.3 20726
        SMSG_BATTLEFIELD_STATUS_WAIT_FOR_GROUPS             = 0x252B, ///< 6.2.3 20726
        SMSG_BATTLEFIELD_PORT_DENIED                        = 0x2517, ///< (unused)
        SMSG_RATED_BATTLEFIELD_INFO                         = 0x252C, ///< 6.2.3 20726
        SMSG_BATTLEGROUND_PLAYER_JOINED                     = 0x2515, ///< 6.2.3 20726
        SMSG_BATTLEGROUND_PLAYER_LEFT                       = 0x2516, ///< 6.2.3 20726
        SMSG_BATTLEGROUND_PLAYER_POSITIONS                  = 0x2512, ///< 6.2.3 20726
        SMSG_BATTLEFIELD_MGR_ENTERING                       = 0x1AD0, ///< 6.2.3 20726
        SMSG_BATTLEFIELD_MGR_QUEUE_REQUEST_RESPONSE         = 0x0B4F, ///< 6.2.3 20726
        SMSG_BATTLEFIELD_MGR_EJECT_PENDING                  = 0x0000, ///< (unused)
        SMSG_BATTLEFIELD_MGR_EJECTED                        = 0x0747, ///< 6.2.3 20726
        SMSG_BATTLEFIELD_MGR_QUEUE_INVITE                   = 0x1E43, ///< 6.2.3 20726
        SMSG_BATTLEFIELD_MGR_STATE_CHANGED                  = 0x0000, ///< (unused)
        SMSG_BFMGR_ENTRY_INVITE                             = 0x02FB, ///< 6.2.3 20726
        SMSG_BATTLEFIELD_MGR_EXIT_REQUEST                   = 0x0000,
        SMSG_REQUEST_PVP_REWARDS_RESPONSE                   = 0x255A, ///< 6.2.3 20726
        SMSG_PVP_OPTIONS_ENABLED                            = 0x253C, ///< 6.2.3 20726
        SMSG_PVPLOG_DATA                                    = 0x0EEF, ///< 6.2.3 20726
        SMSG_ARENA_OPPONENT_SPECIALIZATIONS                 = 0x0F78, ///< 6.2.3 20726
        SMSG_DESTROY_ARENA_UNIT                             = 0x2703, ///< (unused)
        SMSG_BATTLEGROUND_POINTS                            = 0x271D, ///< (unused)
        SMSG_BATTLEGROUND_INIT                              = 0x271E, ///< (unused)
        SMSG_MAP_OBJECTIVES_INIT                            = 0x271F, ///< (unused)
        SMSG_CONQUEST_FORMULA_CONSTANTS                     = 0x2741, ///< 6.2.3 20726
        SMSG_PVP_SEASON                                     = 0x2559, ///< 6.2.3 20726
        SMSG_WARGAME_REQUEST_SUCCESSFULLY_SENT_TO_OPPENENT  = 0x0000, ///< (unused)
        SMSG_SPIRIT_HEALER_CONFIRM                          = 0x26D5, ///< 6.2.3 20726
        SMSG_AREA_SPIRIT_HEALER_TIME                        = 0x2701, ///< 6.2.3 20726
        SMSG_BATTLEFIELD_LIST                               = 0x2511, ///< 6.2.3 20726
        SMSG_CHECK_WARGAME_ENTRY                            = 0x2526, ///< 6.2.3 20726

        /// Pet
        SMSG_PET_NAME_QUERY_RESPONSE                        = 0x0E5F, ///< 6.2.3 20726
        SMSG_PET_NAME_INVALID                               = 0x2671, ///< 6.2.3 20726
        SMSG_PET_DISMISS_SOUND                              = 0x264B, ///< 6.2.3 20726
        SMSG_PET_GUIDS                                      = 0x26C3, ///< 6.2.3 20726
        SMSG_PET_MODE                                       = 0x2506, ///< (unused)
        SMSG_PET_SLOT_UPDATED                               = 0x2505, ///< (unused)
        SMSG_PET_STABLE_LIST                                = 0x252F, ///< 6.2.3 20726
        SMSG_PET_ACTION_FEEDBACK                            = 0x270B, ///< 6.2.3 20726
        SMSG_PET_ACTION_SOUND                               = 0x264A, ///< 6.2.3 20726
        SMSG_PET_ADDED                                      = 0x252E, ///< (unused)
        SMSG_SET_PET_SPECIALIZATION                         = 0x25C2, ///< 6.2.3 20726
        SMSG_STABLE_RESULT                                  = 0x03C3, ///< 6.2.3 20726

        /// Battle pet opcodes
        SMSG_BATTLE_PET_UPDATES                             = 0x2583,   ///< 6.2.3 20726 (unsued)
        SMSG_BATTLE_PET_TRAP_LEVEL                          = 0x2584,   ///< 6.2.3 20726
        SMSG_BATTLE_PET_JOURNAL_LOCK_ACQUIRED               = 0x2586,   ///< 6.2.3 20726
        SMSG_BATTLE_PET_JOURNAL_LOCK_DENIED                 = 0x2587,   ///< 6.2.3 20726
        SMSG_BATTLE_PET_JOURNAL                             = 0x2588,   ///< 6.2.3 20726
        SMSG_BATTLE_PET_DELETED                             = 0x2589,   ///< 6.2.3 20726 (unsued)
        SMSG_BATTLE_PET_REVOKED                             = 0x258A,   ///< 6.2.3 20726 (unsued)
        SMSG_BATTLE_PET_RESTORED                            = 0x258B,   ///< 6.2.3 20726 (unsued)
        SMSG_BATTLE_PETS_HEALED                             = 0x258C,   ///< 6.2.3 20726 (unsued)
        SMSG_BATTLE_PET_LICENSE_CHANGED                     = 0x258D,   ///< 6.2.3 20726 (unsued)
        SMSG_BATTLE_PET_ERROR                               = 0x25D5,   ///< 6.2.3 20726 (unsued)
        SMSG_BATTLE_PET_CAGE_DATE_ERROR                     = 0x2621,   ///< 6.2.3 20726 (unsued)
        SMSG_QUERY_BATTLE_PET_NAME_RESPONSE                 = 0x2685,   ///< 6.2.3 20726

        /// Pet Battle opcodes
        SMSG_PET_BATTLE_SLOT_UPDATES                        = 0x2585,   ///< 6.2.3 20726
        SMSG_PET_BATTLE_REQUEST_FAILED                      = 0x2592,   ///< 6.2.3 20726
        SMSG_PET_BATTLE_PVPCHALLENGE                        = 0x0A63,   ///< 6.2.3 20726
        SMSG_PET_BATTLE_FINALIZE_LOCATION                   = 0x2594,   ///< 6.2.3 20726
        SMSG_PET_BATTLE_INITIAL_UPDATE                      = 0x2595,   ///< 6.2.3 20726
        SMSG_PET_BATTLE_FIRST_ROUND                         = 0x2596,   ///< 6.2.3 20726
        SMSG_PET_BATTLE_ROUND_RESULT                        = 0x2597,   ///< 6.2.3 20726
        SMSG_PET_BATTLE_REPLACEMENTS_MADE                   = 0x2598,   ///< 6.2.3 20726
        SMSG_PET_BATTLE_FINAL_ROUND                         = 0x2599,   ///< 6.2.3 20726
        SMSG_PET_BATTLE_FINISHED                            = 0x259A,   ///< 6.2.3 20726
        SMSG_PET_BATTLE_CHAT_RESTRICTED                     = 0x259B,   ///< 6.2.3 20726
        SMSG_PET_BATTLE_MAX_GAME_LENGTH_WARNING             = 0x259C,   ///< 6.2.3 20726
        SMSG_PET_BATTLE_QUEUE_PROPOSE_MATCH                 = 0x25D6,   ///< 6.2.3 20726
        SMSG_PET_BATTLE_QUEUE_STATUS                        = 0x25D7,   ///< 6.2.3 20726
        SMSG_PET_BATTLE_DEBUG_QUEUE_DUMP_RESPONSE           = 0x261D,   ///< 6.2.3 20726

        /// Instances
        SMSG_INSTANCE_ENCOUNTER_ENGAGE_UNIT                     = 0x2764, ///< 6.2.3 20726
        SMSG_INSTANCE_ENCOUNTER_DISENGAGE_UNIT                  = 0x2765, ///< 6.2.3 20726
        SMSG_INSTANCE_ENCOUNTER_CHANGE_PRIORITY                 = 0x2766, ///< 6.2.3 20726
        SMSG_INSTANCE_ENCOUNTER_TIMER_START                     = 0x2767, ///< 6.2.3 20726
        SMSG_INSTANCE_ENCOUNTER_OBJECTIVE_START                 = 0x2768, ///< 6.2.3 20726
        SMSG_INSTANCE_ENCOUNTER_OBJECTIVE_COMPLETE              = 0x2769, ///< 6.2.3 20726
        SMSG_INSTANCE_ENCOUNTER_START                           = 0x276A, ///< 6.2.3 20726
        SMSG_INSTANCE_ENCOUNTER_OBJECTIVE_UPDATE                = 0x276B, ///< 6.2.3 20726
        SMSG_INSTANCE_ENCOUNTER_END                             = 0x276C, ///< 6.2.3 20726
        SMSG_INSTANCE_ENCOUNTER_IN_COMBAT_RESURRECTION          = 0x276D, ///< 6.2.3 20726
        SMSG_INSTANCE_ENCOUNTER_PHASE_SHIFT_CHANGED             = 0x276F, ///< 6.2.3 20726
        SMSG_INSTANCE_ENCOUNTER_GAIN_COMBAT_RESURRECTION_CHARGE = 0x276E, ///< 6.2.3 20726
        SMSG_INSTANCE_RESET                                     = 0x2630, ///< 6.2.3 20726
        SMSG_INSTANCE_RESET_FAILED                              = 0x2631, ///< 6.2.3 20726
        SMSG_RAID_INSTANCE_INFO                                 = 0x0AE8, ///< 6.2.3 20726
        SMSG_RAID_GROUP_ONLY                                    = 0x2763, ///< 6.2.3 20726
        SMSG_RAID_MARKERS_CHANGED                               = 0x253F, ///< 6.2.3 20726
        SMSG_INSTANCE_SAVE_CREATED                              = 0x2737, ///< 6.2.3 20726
        SMSG_INSTANCE_GROUP_SIZE_CHANGED                        = 0x26B8, ///< 6.2.3 20726
        SMSG_ENCOUNTER_END                                      = 0x2739, ///< 6.2.3 20726
        SMSG_ENCOUNTER_START                                    = 0x2738, ///< 6.2.3 20726
        SMSG_BOSS_KILL_CREDIT                                   = 0x273A, ///< 6.2.3 20726

        /// Scenarios
        SMSG_SCENARIO_POI                                       = 0x1BE3, ///< 6.2.3 20726
        SMSG_SCENARIO_PROGRESS_UPDATE                           = 0x25C9, ///< 6.2.3 20726
        SMSG_SCENARIO_STATE                                     = 0x25C8, ///< 6.2.3 20726

        /// Auction House
        SMSG_AUCTION_HELLO_RESPONSE                             = 0x26A5, ///< 6.2.3 20726
        SMSG_AUCTION_BIDDER_LIST_RESULT                         = 0x027C, ///< 6.2.3 20726
        SMSG_AUCTION_BIDDER_NOTIFICATION                        = 0x1ACB, ///< 6.2.3 20726
        SMSG_AUCTION_BUYOUT_NOTIFICATION                        = 0x0A5C, ///< 6.2.3 20726
        SMSG_AUCTION_COMMAND_RESULT                             = 0x26A7, ///< 6.2.3 20726
        SMSG_AUCTION_CLOSED_NOTIFICATION                        = 0x26AA, ///< 6.2.3 20726
        SMSG_AUCTION_LIST_PENDING_SALES                         = 0x1BEF, ///< 6.2.3 20726
        SMSG_AUCTION_LIST_RESULT                                = 0x1243, ///< 6.2.3 20726
        SMSG_AUCTION_OWNER_LIST_RESULT                          = 0x0BCC, ///< 6.2.3 20726
        SMSG_AUCTION_OWNER_BID_NOTIFICATION                     = 0x26AB, ///< 6.2.3 20726

        /// Mail
        SMSG_SEND_MAIL_RESULT                                   = 0x06D0, ///< 6.2.3 20726
        SMSG_MAIL_LIST_RESULT                                   = 0x2716, ///< 6.2.3 20726
        SMSG_RECEIVED_MAIL                                      = 0x0A73, ///< 6.2.3 20726
        SMSG_MAIL_QUERY_NEXT_TIME_RESULT                        = 0x2717, ///< 6.2.3 20726

        /// Trainers
        SMSG_TRAINER_LIST                                       = 0x2696, ///< 6.2.3 20726
        SMSG_TRAINER_SERVICE                                    = 0x025B, ///< 6.2.3 20726

        /// Void Storage
        SMSG_VOID_ITEM_SWAP_RESPONSE                            = 0x2564, ///< 6.2.3 20726
        SMSG_VOID_STORAGE_CONTENTS                              = 0x2561, ///< 6.2.3 20726
        SMSG_VOID_STORAGE_FAILED                                = 0x2560, ///< 6.2.3 20726
        SMSG_VOID_STORAGE_TRANSFER_CHANGES                      = 0x2562, ///< 6.2.3 20726
        SMSG_VOID_TRANSFER_RESULT                               = 0x2563, ///< 6.2.3 20726

        /// Petition
        SMSG_PETITION_ALREADY_SIGNED                            = 0x253E, ///< 6.2.3 20726
        SMSG_PETITION_SIGN_RESULTS                              = 0x270D, ///< 6.2.3 20726
        SMSG_QUERY_PETITION_RESPONSE                            = 0x2686, ///< 6.2.3 20726
        SMSG_PETITION_SHOW_LIST                                 = 0x266C, ///< 6.2.3 20726
        SMSG_PETITION_SHOW_SIGNATURES                           = 0x266D, ///< 6.2.3 20726
        SMSG_TURN_IN_PETITION_RESULTS                           = 0x16C8, ///< 6.2.3 20726
        SMSG_PETITION_DECLINED                                  = 0x0000, ///< fake opcode

        /// Threat
        SMSG_THREAT_CLEAR                                       = 0x2691, ///< 6.2.3 20726
        SMSG_THREAT_REMOVE                                      = 0x2690, ///< 6.2.3 20726
        SMSG_THREAT_UPDATE                                      = 0x268F, ///< 6.2.3 20726
        SMSG_HIGHEST_THREAT_UPDATE                              = 0x268E, ///< 6.2.3 20726

        /// Tickets
        SMSG_GM_TICKET_SYSTEM_STATUS                            = 0x264D, ///< 6.2.3 20726
        SMSG_GM_TICKET_CASE_STATUS                              = 0x264E, ///< 6.2.3 20726

        /// Calendar
        SMSG_CALENDAR_CLEAR_PENDING_ACTION                      = 0x2647, ///< 6.2.3 20726
        SMSG_CALENDAR_COMMAND_RESULT                            = 0x2648, ///< 6.2.3 20726
        SMSG_CALENDAR_EVENT_INITIAL_INVITE                      = 0x0777, ///< 6.2.3 20726
        SMSG_CALENDAR_EVENT_INVITE                              = 0x2638, ///< 6.2.3 20726
        SMSG_CALENDAR_EVENT_INVITE_ALERT                        = 0x2639, ///< 6.2.3 20726
        SMSG_CALENDAR_EVENT_INVITE_NOTES                        = 0x2641, ///< 6.2.3 20726
        SMSG_CALENDAR_EVENT_INVITE_NOTES_ALERT                  = 0x2642, ///< 6.2.3 20726
        SMSG_CALENDAR_EVENT_INVITE_REMOVED                      = 0x263D, ///< 6.2.3 20726
        SMSG_CALENDAR_EVENT_INVITE_REMOVED_ALERT                = 0x263E, ///< 6.2.3 20726
        SMSG_CALENDAR_EVENT_INVITE_STATUS                       = 0x263A, ///< 6.2.3 20726
        SMSG_CALENDAR_EVENT_INVITE_STATUS_ALERT                 = 0x263B, ///< 6.2.3 20726
        SMSG_CALENDAR_EVENT_MODERATOR_STATUS                    = 0x0244, ///< 6.2.3 20726
        SMSG_CALENDAR_EVENT_REMOVED_ALERT                       = 0x263F, ///< 6.2.3 20726
        SMSG_CALENDAR_EVENT_UPDATED_ALERT                       = 0x2640, ///< 6.2.3 20726
        SMSG_CALENDAR_RAID_LOCKOUT_ADDED                        = 0x2643, ///< 6.2.3 20726
        SMSG_CALENDAR_RAID_LOCKOUT_REMOVED                      = 0x2644, ///< 6.2.3 20726
        SMSG_CALENDAR_RAID_LOCKOUT_UPDATED                      = 0x2645, ///< 6.2.3 20726
        SMSG_CALENDAR_SEND_CALENDAR                             = 0x2635, ///< 6.2.3 20726
        SMSG_CALENDAR_SEND_EVENT                                = 0x2636, ///< 6.2.3 20726
        SMSG_CALENDAR_SEND_NUM_PENDING                          = 0x2646, ///< 6.2.3 20726

        /// Warden
        SMSG_WARDEN_DATA                                        = 0x24F4, ///< 6.2.3 20726

        /// Challenges
        SMSG_CHALLENGE_MODE_REQUEST_LEADERS_RESULT              = 0x25A6, ///< 6.2.3 20726
        SMSG_CHALLENGE_MODE_MAP_STATS_UPDATE                    = 0x25A5, ///< 6.2.3 20726
        SMSG_CHALLENGE_MODE_NEW_PLAYER_RECORD                   = 0x25A7, ///< 6.2.3 20726
        SMSG_CHALLENGE_MODE_ALL_MAP_STATS                       = 0x25A4, ///< 6.2.3 20726
        SMSG_CHALLENGE_MODE_START                               = 0x25A0, ///< This opcode is wrong and not existing
        SMSG_CHALLENGE_MODE_COMPLETE                            = 0x25A2, ///< 6.2.3 20726
        SMSG_CHALLENGE_MOD_REWARDS                              = 0x0000, ///< (NYI)

        /// Battlepay
        SMSG_BATTLE_PAY_GET_PRODUCT_LIST_RESPONSE               = 0x2730, ///< 6.2.3 20726
        SMSG_BATTLE_PAY_GET_PURCHASE_LIST_RESPONSE              = 0x2731, ///< 6.2.3 20726
        SMSG_BATTLE_PAY_GET_DISTRIBUTION_LIST_RESPONSE          = 0x2732, ///< 6.2.3 20726
        SMSG_BATTLE_PAY_START_PURCHASE_RESPONSE                 = 0x273B, ///< 6.2.3 20726
        SMSG_BATTLE_PAY_PURCHASE_UPDATE                         = 0x273E, ///< 6.2.3 20726
        SMSG_BATTLE_PAY_CONFIRM_PURCHASE                        = 0x273F, ///< 6.2.3 20726

        /// Black Market
        SMSG_BLACK_MARKET_OPEN_RESULT                           = 0x25C3, ///< 6.2.3 20726
        SMSG_BLACK_MARKET_OUTBID                                = 0x25C6, ///< 6.2.3 20726
        SMSG_BLACK_MARKET_REQUEST_ITEMS_RESULT                  = 0x25C4, ///< 6.2.3 20726
        SMSG_BLACK_MARKET_BID_ON_ITEM_RESULT                    = 0x25C5, ///< 6.2.3 20726
        SMSG_BLACK_MARKET_WON                                   = 0x25C7, ///< 6.2.3 20726

        /// Garrison
        SMSG_OPEN_SHIPMENT_NPCFROM_GOSSIP                       = 0x1657, ///< 6.2.3 20726
        SMSG_GET_SHIPMENT_INFO_RESPONSE                         = 0x2755, ///< 6.2.3 20726
        SMSG_GARRISON_LANDING_PAGE_SHIPMENT_INFO                = 0x275A, ///< 6.2.3 20726
        SMSG_CREATE_SHIPMENT_RESPONSE                           = 0x2757, ///< 6.2.3 20726

        /// Twitter
        SMSG_REQUEST_TWITTER_STATUS_RESPONSE                    = 0x0000,
        SMSG_OAUTH_SAVED_DATA                                   = 0x0060, ///< 6.2.3 20726

        /// Toys
        SMSG_ACCOUNT_TOYS_UPDATE                                = 0x254A, ///< 6.2.3 20726

        /// AreaTriggers
        SMSG_AREA_TRIGGER_RE_SHAPE                              = 0x25C1, ///< 6.2.3 20726
        SMSG_AREA_TRIGGER_RE_PATH                               = 0x25BF, ///< 6.2.3 20726
    #pragma endregion

    //////////////////////////////////////////////////////////////////////////
    /// Jam Client Guild
    //////////////////////////////////////////////////////////////////////////
    #pragma region JamGuild
        /// Petition
        SMSG_PETITION_RENAME                        = 0x141F, ///< 6.2.3 20726

        /// Guild Finder
        SMSG_LFGUILD_BROWSE                         = 0x154C, ///< 6.2.3 20726
        SMSG_LFGUILD_APPLICATIONS                   = 0x1460, ///< 6.2.3 20726
        SMSG_LFGUILD_APPLICATIONS_LIST_CHANGED      = 0x1503, ///< 6.2.3 20726
        SMSG_LFGUILD_COMMAND_RESULT                 = 0x0000, ///< (unused)
        SMSG_LFGUILD_RECRUITS                       = 0x1453, ///< 6.2.3 20726
        SMSG_LFGUILD_POST                           = 0x1450, ///< 6.2.3 20726
        SMSG_LFGUILD_APPLICANT_LIST_CHANGED         = 0x1587, ///< 6.2.3 20726

        /// Bank
        SMSG_GUILD_RANKS                            = 0x2946, ///< 6.2.3 20726
        SMSG_GUILD_BANK_LOG_QUERY_RESULT            = 0x1413, ///< 6.2.3 20726
        SMSG_GUILD_BANK_REMAINING_WITHDRAW_MONEY    = 0x295D, ///< 6.2.3 20726
        SMSG_GUILD_BANK_QUERY_TEXT_RESULT           = 0x155C, ///< 6.2.3 20726
        SMSG_GUILD_BANK_QUERY_RESULTS               = 0x295B, ///< 6.2.3 20726
        SMSG_GUILD_PERMISSIONS_QUERY_RESULTS        = 0x295E, ///< 6.2.3 20726

        /// Achievement
        SMSG_GUILD_ACHIEVEMENT_DELETED              = 0x2943, ///< 6.2.3 20726
        SMSG_GUILD_ACHIEVEMENT_MEMBERS              = 0x2945, ///< (unused)
        SMSG_GUILD_ACHIEVEMENT_EARNED               = 0x2942, ///< 6.2.3 20726
        SMSG_GUILD_CRITERIA_UPDATE                  = 0x2941, ///< (unused)
        SMSG_GUILD_CRITERIA_DELETED                 = 0x2944, ///< 6.2.3 20726
        SMSG_ALL_GUILD_ACHIEVEMENTS                 = 0x2936, ///< 6.2.3 20726

        /// Info
        SMSG_GUILD_ROSTER                           = 0x2939, ///< 6.2.3 20726
        SMSG_GUILD_ROSTER_UPDATE                    = 0x293A, ///< (unused)
        SMSG_QUERY_GUILD_INFO_RESPONSE              = 0x2962, ///< 6.2.3 20726
        SMSG_GUILD_MEMBER_UPDATE_NOTE               = 0x2947, ///< (unused)
        SMSG_GUILD_REWARDS_LIST                     = 0x1410, ///< 6.2.3 20726
        SMSG_GUILD_SEND_RANK_CHANGE                 = 0x2937, ///< 6.2.3 20726
        SMSG_GUILD_CHALLENGE_UPDATED                = 0x140F, ///< 6.2.3 20726
        SMSG_GUILD_MEMBER_RECIPES                   = 0x293B, ///< (unused)
        SMSG_GUILD_INVITE_EXPIRED                   = 0x2964, ///< (unused)
        SMSG_GUILD_COMMAND_RESULT                   = 0x2938, ///< 6.2.3 20726
        SMSG_GUILD_CHALLENGE_COMPLETED              = 0x2951, ///< 6.2.3 20726
        SMSG_GUILD_REPUTATION_REACTION_CHANGED      = 0x294A, ///< 6.2.3 20726
        SMSG_GUILD_KNOWN_RECIPES                    = 0x293C, ///< 6.2.3 20726
        SMSG_GUILD_MEMBER_DAILY_RESET               = 0x2961, ///< 6.2.3 20726
        SMSG_GUILD_FLAGGED_FOR_RENAME               = 0x2959, ///< (unused)
        SMSG_GUILD_NAME_CHANGED                     = 0x2958, ///< (unused)
        SMSG_GUILD_RESET                            = 0x2955, ///< (unused)
        SMSG_GUILD_CHANGE_NAME_RESULT               = 0x295A, ///< (unused)
        SMSG_GUILD_INVITE                           = 0x2948, ///< 6.2.3 20726
        SMSG_GUILD_INVITE_DECLINED                  = 0x2963, ///< (unused)
        SMSG_GUILD_PARTY_STATE                      = 0x2949, ///< 6.2.3 20726
        SMSG_GUILD_MEMBERS_WITH_RECIPE              = 0x293D, ///< (unused)
        SMSG_GUILD_MOVE_STARTING                    = 0x2956, ///< (unused)
        SMSG_GUILD_MOVED                            = 0x2957, ///< (unused)
        SMSG_GUILD_NEWS                             = 0x293F, ///< 6.2.3 20726
        SMSG_GUILD_NEWS_DELETED                     = 0x2940, ///< (unused)
        SMSG_PLAYER_TABAR_VENDOR_SHOW               = 0x16C3, ///< 6.2.3 20726
        SMSG_PLAYER_SAVE_GUILD_EMBLEM               = 0x2973, ///< 6.2.3 20726

        /// Event system
        SMSG_GUILD_EVENT_NEW_LEADER                 = 0x2967, ///< 6.2.3 20726
        SMSG_GUILD_EVENT_PRESENCE_CHANGE            = 0x296A, ///< 6.2.3 20726
        SMSG_GUILD_EVENT_PLAYER_JOINED              = 0x2965, ///< 6.2.3 20726
        SMSG_GUILD_EVENT_PLAYER_LEFT                = 0x2966, ///< 6.2.3 20726
        SMSG_GUILD_EVENT_RANKS_UPDATED              = 0x296B, ///< 6.2.3 20726
        SMSG_GUILD_EVENT_RANK_CHANGED               = 0x296C, ///< 6.2.3 20726
        SMSG_GUILD_EVENT_LOG_QUERY_RESULTS          = 0x295F, ///< 6.2.3 20726
        SMSG_GUILD_EVENT_MOTD                       = 0x2969, ///< 6.2.3 20726
        SMSG_GUILD_EVENT_DISBANDED                  = 0x2968, ///< 6.2.3 20726
        SMSG_GUILD_EVENT_TAB_ADDED                  = 0x296D, ///< 6.2.3 20726
        SMSG_GUILD_EVENT_TAB_MODIFIED               = 0x296F, ///< 6.2.3 20726
        SMSG_GUILD_EVENT_TAB_DELETED                = 0x296E, ///< 6.2.3 20726
        SMSG_GUILD_EVENT_TAB_TEXT_CHANGED           = 0x2970, ///< 6.2.3 20726
        SMSG_GUILD_EVENT_BANK_CONTENTS_CHANGED      = 0x2972, ///< 6.2.3 20726
        SMSG_GUILD_EVENT_BANK_MONEY_CHANGED         = 0x2971, ///< 6.2.3 20726
    #pragma endregion

    //////////////////////////////////////////////////////////////////////////
    /// Jam Client Chat
    //////////////////////////////////////////////////////////////////////////
    #pragma region JamChat
        /// Voice chat
        SMSG_VOICE_SESSION_ROSTER_UPDATE            = 0x2B33, ///< (unused)
        SMSG_VOICE_SESSION_LEAVE                    = 0x2B34, ///< (unused)
        SMSG_VOICE_PARENTAL_CONTROLS                = 0x2B32, ///< (unused)
        SMSG_VOICE_CHAT_STATUS                      = 0x2B31, ///< (unused)
        SMSG_AVAILABLE_VOICE_CHANNEL                = 0x2B30, ///< (unused)

        /// Misc
        SMSG_SERVER_FIRST_ACHIEVEMENT               = 0x2B3F, ///< 6.2.3 20726
        SMSG_RAID_INSTANCE_MESSAGE                  = 0x2B37, ///< 6.2.3 20726
        SMSG_MOTD                                   = 0x2B2D, ///< 6.2.3 20726
        SMSG_EXPECTED_SPAM_RECORDS                  = 0x2B2F, ///< (unused)
        SMSG_DEFENSE_MESSAGE                        = 0x2B39, ///< (unused)
        SMSG_ZONE_UNDER_ATTACK                      = 0x2B38, ///< 6.2.3 20726
        SMSG_WHO                                    = 0x2B2C, ///< 6.2.3 20726

        /// Chat
        SMSG_CHAT_SERVER_MESSAGE                    = 0x2B47, ///< 6.2.3 20726
        SMSG_CHAT_RESTRICTED                        = 0x2B36, ///< 6.2.3 20726
        SMSG_CHAT_RECONNECT                         = 0x2B42, ///< (unused)
        SMSG_CHAT_PLAYER_NOTFOUND                   = 0x2B3A, ///< 6.2.3 20726
        SMSG_CHAT_PLAYER_AMBIGUOUS                  = 0x2B2E, ///< 6.2.3 20726
        SMSG_CHAT_NOT_IN_PARTY                      = 0x2B35, ///< (unused)
        SMSG_CHAT_IS_DOWN                           = 0x2B41, ///< (unused)
        SMSG_CHAT_IGNORED_ACCOUNT_MUTED             = 0x2B2A, ///< (unused)
        SMSG_CHAT_DOWN                              = 0x2B40, ///< (unused)
        SMSG_CHAT_AUTO_RESPONDED                    = 0x2B3B, ///< (unused)
        SMSG_CHAT                                   = 0x2B2B, ///< 6.2.3 20726

        /// Channel
        SMSG_CHANNEL_NOTIFY_LEFT                    = 0x2B45, ///< 6.2.3 20726
        SMSG_CHANNEL_NOTIFY_JOINED                  = 0x2B44, ///< 6.2.3 20726
        SMSG_CHANNEL_NOTIFY                         = 0x2B43, ///< 6.2.3 20726
        SMSG_CHANNEL_LIST                           = 0x2B46, ///< 6.2.3 20726
        SMSG_USERLIST_ADD                           = 0x2B3C, ///< 6.2.3 20726
        SMSG_USERLIST_REMOVE                        = 0x2B3D, ///< 6.2.3 20726
        SMSG_USERLIST_UPDATE                        = 0x2B3E, ///< 6.2.3 20726
    #pragma endregion

    //////////////////////////////////////////////////////////////////////////
    /// Jam Client Move
    //////////////////////////////////////////////////////////////////////////
    #pragma region JamMove
        /// Move speeds
        SMSG_MOVE_SET_RUN_SPEED                     = 0x2D3C, ///< 6.2.3 20726
        SMSG_MOVE_SET_RUN_BACK_SPEED                = 0x2D3D, ///< 6.2.3 20726
        SMSG_MOVE_SET_SWIM_SPEED                    = 0x2D3E, ///< 6.2.3 20726
        SMSG_MOVE_SET_SWIM_BACK_SPEED               = 0x2D3F, ///< 6.2.3 20726
        SMSG_MOVE_SET_FLIGHT_SPEED                  = 0x2D40, ///< 6.2.3 20726
        SMSG_MOVE_SET_FLIGHT_BACK_SPEED             = 0x2D41, ///< 6.2.3 20726
        SMSG_MOVE_SET_WALK_SPEED                    = 0x2D42, ///< 6.2.3 20726
        SMSG_MOVE_SET_TURN_RATE                     = 0x2D43, ///< 6.2.3 20726
        SMSG_MOVE_SET_PITCH_RATE                    = 0x2D44, ///< 6.2.3 20726
        SMSG_MOVE_KNOCK_BACK                        = 0x2D4D, ///< 6.2.3 20726
        SMSG_MOVE_UPDATE_RUN_SPEED                  = 0x2D22, ///< 6.2.3 20726
        SMSG_MOVE_UPDATE_RUN_BACK_SPEED             = 0x2D23, ///< 6.2.3 20726
        SMSG_MOVE_UPDATE_SWIM_SPEED                 = 0x2D25, ///< 6.2.3 20726
        SMSG_MOVE_UPDATE_SWIM_BACK_SPEED            = 0x2D26, ///< 6.2.3 20726
        SMSG_MOVE_UPDATE_FLIGHT_SPEED               = 0x2D27, ///< 6.2.3 20726
        SMSG_MOVE_UPDATE_FLIGHT_BACK_SPEED          = 0x2D28, ///< 6.2.3 20726
        SMSG_MOVE_UPDATE_WALK_SPEED                 = 0x2D24, ///< 6.2.3 20726
        SMSG_MOVE_UPDATE_TURN_RATE                  = 0x2D29, ///< 6.2.3 20726
        SMSG_MOVE_UPDATE_PITCH_RATE                 = 0x2D2A, ///< 6.2.3 20726
        SMSG_MOVE_UPDATE_KNOCK_BACK                 = 0x2D2E, ///< 6.2.3 20726

        /// Player
        SMSG_MOVE_UPDATE                                    = 0x2D2C, ///< 6.2.3 20726
        SMSG_MOVE_TELEPORT                                  = 0x2D4E, ///< 6.2.3 20726
        SMSG_MOVE_UPDATE_TELEPORT                           = 0x2D2D, ///< 6.2.3 20726
        SMSG_MOVE_ROOT                                      = 0x2D45, ///< 6.2.3 20726
        SMSG_MOVE_UNROOT                                    = 0x2D46, ///< 6.2.3 20726
        SMSG_MOVE_WATER_WALK                                = 0x00F1, ///< 6.2.3 20726
        SMSG_MOVE_LAND_WALK                                 = 0x09A1, ///< 6.2.3 20726
        SMSG_MOVE_FEATHER_FALL                              = 0x0425, ///< 6.2.3 20726
        SMSG_MOVE_NORMAL_FALL                               = 0x00F6, ///< 6.2.3 20726
        SMSG_MOVE_SET_ACTIVE_MOVER                          = 0x2D21, ///< 6.2.3 20726
        SMSG_MOVE_SET_CAN_FLY                               = 0x2D4F, ///< 6.2.3 20726
        SMSG_MOVE_UNSET_CAN_FLY                             = 0x2D50, ///< 6.2.3 20726
        SMSG_MOVE_SET_HOVER                                 = 0x04EA, ///< 6.2.3 20726
        SMSG_MOVE_UNSET_HOVER                               = 0x0535, ///< 6.2.3 20726
        SMSG_MOVE_SET_CAN_TURN_WHILE_FALLING                = 0x2D51, ///< 6.2.3 20726
        SMSG_MOVE_UNSET_CAN_TURN_WHILE_FALLING              = 0x2D52, ///< 6.2.3 20726
        SMSG_MOVE_SET_CAN_TRANSITION_BETWEEN_SWIM_AND_FLY   = 0x0906, ///< 6.2.3 20726
        SMSG_MOVE_UNSET_CAN_TRANSITION_BETWEEN_SWIM_AND_FLY = 0x0D3A, ///< 6.2.3 20726
        SMSG_MOVE_SET_VEHICLE_REC_ID                        = 0x2D5C, ///< 6.2.3 20726
        SMSG_MOVE_SET_COLLISION_HEIGHT                      = 0x2D5B, ///< 6.2.3 20726
        SMSG_APPLY_MOVEMENT_FORCE                           = 0x0C62, ///< 6.2.3 20726
        SMSG_UNAPPLY_MOVEMENT_FORCE                         = 0x01E2, ///< 6.2.3 20726
        SMSG_MOVE_SKIP_TIME                                 = 0x2D60, ///< (unused)
        SMSG_MOVE_ENABLE_GRAVITY                            = 0x2D58, ///< (unused)
        SMSG_MOVE_DISABLE_GRAVITY                           = 0x2D57, ///< (unused)
        SMSG_MOVE_ENABLE_COLLISION                          = 0x2D5A, ///< (unused)
        SMSG_MOVE_DISABLE_COLLISION                         = 0x2D59, ///< (unused)

        /// Creature
        SMSG_MONSTER_MOVE                           = 0x043A, ///< 6.2.3 20726
        SMSG_SPLINE_MOVE_SET_RUN_SPEED              = 0x0DE1, ///< 6.2.3 20726
        SMSG_SPLINE_MOVE_SET_RUN_BACK_SPEED         = 0x053A, ///< 6.2.3 20726
        SMSG_SPLINE_MOVE_SET_SWIM_SPEED             = 0x05F2, ///< 6.2.3 20726
        SMSG_SPLINE_MOVE_SET_SWIM_BACK_SPEED        = 0x0031, ///< 6.2.3 20726
        SMSG_SPLINE_MOVE_SET_FLIGHT_SPEED           = 0x0D01, ///< 6.2.3 20726
        SMSG_SPLINE_MOVE_SET_FLIGHT_BACK_SPEED      = 0x05F1, ///< 6.2.3 20726
        SMSG_SPLINE_MOVE_SET_WALK_SPEED             = 0x0401, ///< 6.2.3 20726
        SMSG_SPLINE_MOVE_SET_TURN_RATE              = 0x002A, ///< 6.2.3 20726
        SMSG_SPLINE_MOVE_SET_PITCH_RATE             = 0x0D79, ///< 6.2.3 20726
        SMSG_SPLINE_MOVE_ROOT                       = 0x05E2, ///< 6.2.3 20726
        SMSG_SPLINE_MOVE_UNROOT                     = 0x0032, ///< 6.2.3 20726
        SMSG_SPLINE_MOVE_GRAVITY_DISABLE            = 0x0465, ///< 6.2.3 20726
        SMSG_SPLINE_MOVE_GRAVITY_ENABLE             = 0x0171, ///< 6.2.3 20726
        SMSG_SPLINE_MOVE_COLLISION_DISABLE          = 0x0000, ///< (unused)
        SMSG_SPLINE_MOVE_COLLISION_ENABLE           = 0x0000, ///< (unused)
        SMSG_SPLINE_MOVE_SET_FEATHER_FALL           = 0x08A6, ///< 6.2.3 20726
        SMSG_SPLINE_MOVE_SET_NORMAL_FALL            = 0x0C79, ///< 6.2.3 20726
        SMSG_SPLINE_MOVE_SET_HOVER                  = 0x00ED, ///< 6.2.3 20726
        SMSG_SPLINE_MOVE_UNSET_HOVER                = 0x0D4D, ///< 6.2.3 20726
        SMSG_SPLINE_MOVE_SET_WATER_WALK             = 0x0865, ///< 6.2.3 20726
        SMSG_SPLINE_MOVE_SET_LAND_WALK              = 0x04A6, ///< 6.2.3 20726
        SMSG_SPLINE_MOVE_START_SWIM                 = 0x0000, ///< (unused)
        SMSG_SPLINE_MOVE_STOP_SWIM                  = 0x0000, ///< (unused)
        SMSG_SPLINE_MOVE_SET_RUN_MODE               = 0x040E, ///< 6.2.3 20726
        SMSG_SPLINE_MOVE_SET_WALK_MODE              = 0x09AE, ///< 6.2.3 20726
        SMSG_SPLINE_MOVE_SET_FLYING                 = 0x0475, ///< 6.2.3 20726
        SMSG_SPLINE_MOVE_UNSET_FLYING               = 0x057E, ///< 6.2.3 20726
        SMSG_FLIGHT_SPLINE_SYNC                     = 0x2D73, ///< 6.2.3 20726
    #pragma endregion

    //////////////////////////////////////////////////////////////////////////
    /// Jam Client Spell
    //////////////////////////////////////////////////////////////////////////
    #pragma region JamSpell
        /// Aura
        SMSG_AURA_POINTS_DEPLETED                   = 0x2BA0, ///< (unused)
        SMSG_AURA_UPDATE                            = 0x2B9F, ///< 6.2.3 20726

        /// Misc
        SMSG_CHEAT_IGNORE_DIMISHING_RETURNS         = 0x2B90, ///< (unused)
        SMSG_DISPEL_FAILED                          = 0x2BAE, ///< 6.2.3 20726
        SMSG_INCREASE_CAST_TIME_FOR_SPELL           = 0x2BA4, ///< (unused)
        SMSG_MIRROR_IMAGE_COMPONENTED_DATA          = 0x2B92, ///< 6.2.3 20726
        SMSG_MIRROR_IMAGE_CREATURE_DATA             = 0x2B91, ///< (unused)
        SMSG_PET_CLEAR_SPELLS                       = 0x2BA1, ///< (unused)
        SMSG_REFRESH_SPELL_HISTORY                  = 0x2BAA, ///< (unused)
        SMSG_RESUME_CAST_BAR                        = 0x2BBB, ///< (unused)
        SMSG_CAST_FAILED                            = 0x2BD2, ///< 6.2.3 20726
        SMSG_SPELL_FAILURE                          = 0x2BCF, ///< 6.2.3 20726
        SMSG_SPELL_FAILED_OTHER                     = 0x2BD0, ///< 6.2.3 20726
        SMSG_PET_CAST_FAILED                        = 0x2BD3, ///< 6.2.3 20726
        SMSG_ITEM_COOLDOWN                          = 0x2779, ///< 6.2.3 20726
        SMSG_MODIFY_COOLDOWN                        = 0x2725, ///< 6.2.3 20726
        SMSG_COOLDOWN_CHEAT                         = 0x26F9, ///< (unused)
        SMSG_PET_TAME_FAILURE                       = 0x265F, ///< 6.2.3 20726
        SMSG_FEIGN_DEATH_RESISTED                   = 0x2705, ///< 6.2.3 20726
        SMSG_NOTIFY_DEST_LOC_SPELL_CAST             = 0x2BC1, ///< (unused)
        SMSG_ON_CANCEL_EXPECTED_RIDE_VEHICLE_AURA   = 0x269E, ///< 6.2.3 20726
        SMSG_SET_VEHICLE_REC_ID                     = 0x26B1, ///< 6.2.3 20726
        SMSG_COOLDOWN_EVENT                         = 0x2666, ///< 6.2.3 20726
        SMSG_DISMOUNT                               = 0x265C, ///< 6.2.3 20726
        SMSG_DISMOUNTRESULT                         = 0x0000, ///< (unused)
        SMSG_MOUNT_RESULT                           = 0x24F8, ///< 6.2.3 20726

        /// Spell Book / Bar
        SMSG_UPDATE_WEEKLY_SPELL_USAGE              = 0x2B97, ///< (unused)
        SMSG_WEEKLY_SPELL_USAGE                     = 0x2B96, ///< (unused)
        SMSG_SEND_KNOWN_SPELLS                      = 0x2BA8, ///< 6.2.3 20726
        SMSG_SEND_SPELL_CHARGES                     = 0x2BAB, ///< 6.2.3 20726
        SMSG_SEND_SPELL_HISTORY                     = 0x2BA9, ///< 6.2.3 20726
        SMSG_SEND_UNLEARN_SPELLS                    = 0x2BAC, ///< (unused)
        SMSG_CLEAR_ALL_SPELL_CHARGES                = 0x2BA5, ///< 6.2.3 20726
        SMSG_CLEAR_COOLDOWN                         = 0x2667, ///< 6.2.3 20726
        SMSG_CLEAR_COOLDOWNS                        = 0x2BA3, ///< 6.2.3 20726
        SMSG_CATEGORY_COOLDOWN                      = 0x2B94, ///< 6.2.3 20726
        SMSG_CLEAR_SPELL_CHARGES                    = 0x2BA6, ///< 6.2.3 20726
        SMSG_SET_FLAT_SPELL_MODIFIER                = 0x2BB5, ///< 6.2.3 20726
        SMSG_SET_PCT_SPELL_MODIFIER                 = 0x2BB6, ///< 6.2.3 20726
        SMSG_SET_SPELL_CHARGES                      = 0x2BA7, ///< 6.2.3 20726
        SMSG_LEARNED_SPELL                          = 0x05A7, ///< 6.2.3 20726
        SMSG_UNLEARNED_SPELLS                       = 0x2BCC, ///< 6.2.3 20726

        /// Casting
        SMSG_SPELL_CHANNEL_START                    = 0x2BB3, ///< 6.2.3 20726
        SMSG_SPELL_COOLDOWN                         = 0x2B93, ///< 6.2.3 20726
        SMSG_SPELL_CHANNEL_UPDATE                   = 0x2BB4, ///< 6.2.3 20726
        SMSG_SPELL_DAMAGE_SHIELD                    = 0x2BAF, ///< 6.2.3 20726
        SMSG_SPELL_DELAYED                          = 0x2BBC, ///< 6.2.3 20726
        SMSG_SPELL_GO                               = 0x2BB7, ///< 6.2.3 20726
        SMSG_SPELL_MULTISTRIKE_EFFECT               = 0x2BC0, ///< (unused)
        SMSG_SPELL_OR_DAMAGE_IMMUNE                 = 0x2BAD, ///< 6.2.3 20726
        SMSG_SPELL_START                            = 0x2BB8, ///< 6.2.3 20726
        SMSG_SPELL_UPDATE_CHAIN_TARGETS             = 0x2BB2, ///< (unused)

        /// Logging
        SMSG_SPELL_DISPELL_LOG                      = 0x2B98, ///< 6.2.3 20726
        SMSG_SPELL_ENERGIZE_LOG                     = 0x2B9A, ///< 6.2.3 20726
        SMSG_SPELL_EXECUTE_LOG                      = 0x2BBD, ///< 6.2.3 20726
        SMSG_SPELL_NON_MELEE_DAMAGE_LOG             = 0x2BB0, ///< 6.2.3 20726
        SMSG_SPELL_HEAL_LOG                         = 0x2B9B, ///< 6.2.3 20726
        SMSG_SPELL_INSTAKILL_LOG                    = 0x2BB1, ///< 6.2.3 20726
        SMSG_SPELL_INTERRUPT_LOG                    = 0x2B9D, ///< 6.2.3 20726
        SMSG_SPELL_MISS_LOG                         = 0x2BBE, ///< 6.2.3 20726
        SMSG_ENVIRONMENTAL_DAMAGE_LOG               = 0x2B9E, ///< 6.2.3 20726
        SMSG_SPELL_PERIODIC_AURA_LOG                = 0x2B99, ///< 6.2.3 20726
        SMSG_SPELL_PROC_SCRIPT_LOG                  = 0x0000, ///< Debug opcode (disabled)
        SMSG_SPELL_PROCS_PER_MINUTE_LOG             = 0x0000, ///< Debug opcode (disabled)
        SMSG_SPELL_CHANCE_PROC_LOG                  = 0x0000, ///< Debug opcode (disabled)
        SMSG_RESIST_LOG                             = 0x0000, ///< Debug opcode (disabled)
        SMSG_AURA_CAST_LOG                          = 0x0000, ///< Debug opcode (disabled)

        /// Pet
        SMSG_PET_SPELLS_MESSAGE                     = 0x2BA2, ///< 6.2.3 20726
        SMSG_PET_UNLEARNED_SPELLS                   = 0x2BCE, ///< 6.2.3 20726
        SMSG_PET_LEARNED_SPELLS                     = 0x2BCD, ///< 6.2.3 20726

        /// Visuals
        SMSG_PLAY_ORPHAN_SPELL_VISUAL               = 0x2BC5, ///< 6.2.3 20726
        SMSG_CANCEL_ORPHAN_SPELL_VISUAL             = 0x2BC4, ///< 6.2.3 20726
        SMSG_PLAY_SPELL_VISUAL                      = 0x2BC3, ///< 6.2.3 20726
        SMSG_CANCEL_SPELL_VISUAL                    = 0x2BC2, ///< 6.2.3 20726
        SMSG_PLAY_SPELL_VISUAL_KIT                  = 0x2BC7, ///< 6.2.3 20726
        SMSG_CANCEL_SPELL_VISUAL_KIT                = 0x2BC6, ///< 6.2.3 20726
    #pragma endregion

    //////////////////////////////////////////////////////////////////////////
    /// Jam Client Quest
    //////////////////////////////////////////////////////////////////////////
    #pragma region JamQuest
        /// Quest log
        SMSG_QUERY_QUEST_INFO_RESPONSE              = 0x2A12, ///< 6.2.3 20726
        SMSG_QUEST_UPDATE_FAILED_TIMER              = 0x2A07, ///< 6.2.3 20726
        SMSG_QUEST_UPDATE_FAILED                    = 0x2A06, ///< 6.2.3 20726
        SMSG_QUEST_UPDATE_COMPLETE                  = 0x2A05, ///< 6.2.3 20726
        SMSG_QUEST_UPDATE_ADD_PVP_CREDIT            = 0x2A0A, ///< 6.2.3 20726
        SMSG_QUEST_UPDATE_ADD_CREDIT_SIMPLE         = 0x2A09, ///< 6.2.3 20726
        SMSG_QUEST_UPDATE_ADD_CREDIT                = 0x2A08, ///< 6.2.3 20726
        SMSG_QUEST_PUSH_RESULT                      = 0x2A0C, ///< 6.2.3 20726
        SMSG_QUEST_POIQUERY_RESPONSE                = 0x1D82, ///< 6.2.3 20726
        SMSG_QUEST_LOG_FULL                         = 0x2A04, ///< 6.2.3 20726
        SMSG_IS_QUEST_COMPLETE_RESPONSE             = 0x2A01, ///< 6.2.3 20726
        SMSG_QUEST_FORCE_REMOVED                    = 0x2A17, ///< 6.2.3 20726
        SMSG_QUEST_CONFIRM_ACCEPT                   = 0x2A0B, ///< 6.2.3 20726
        SMSG_QUEST_COMPLETION_NPCRESPONSE           = 0x0442, ///< 6.2.3 20726
        SMSG_DAILY_QUESTS_RESET                     = 0x29FE, ///< 6.2.3 20726

        /// Quest giver
        SMSG_QUEST_GIVER_STATUS_MULTIPLE            = 0x2A0D, ///< 6.2.3 20726
        SMSG_QUEST_GIVER_STATUS                     = 0x2A16, ///< 6.2.3 20726
        SMSG_QUEST_GIVER_REQUEST_ITEMS              = 0x2A0F, ///< 6.2.3 20726
        SMSG_QUEST_GIVER_QUEST_LIST_MESSAGE         = 0x2A15, ///< 6.2.3 20726
        SMSG_QUEST_GIVER_QUEST_FAILED               = 0x2A03, ///< 6.2.3 20726
        SMSG_QUEST_GIVER_QUEST_DETAILS              = 0x2A0E, ///< 6.2.3 20726
        SMSG_QUEST_GIVER_QUEST_COMPLETE             = 0x2A00, ///< 6.2.3 20726
        SMSG_QUEST_GIVER_OFFER_REWARD_MESSAGE       = 0x2A10, ///< 6.2.3 20726
        SMSG_QUEST_GIVER_INVALID_QUEST              = 0x2A02, ///< 6.2.3 20726

        /// Gossip
        SMSG_GOSSIP_MESSAGE                         = 0x2A14, ///< 6.2.3 20726
        SMSG_GOSSIP_COMPLETE                        = 0x2A13, ///< 6.2.3 20726
    #pragma endregion

    //////////////////////////////////////////////////////////////////////////
    /// Jam Client Lfg
    //////////////////////////////////////////////////////////////////////////
    #pragma region JamLFG
        /// LFG
        SMSG_LFG_BOOT_PLAYER                              = 0x29B4, ///< 6.2.3 20726
        SMSG_LFG_DISABLED                                 = 0x29B2, ///< 6.2.3 20726
        SMSG_LFG_JOIN_RESULT                              = 0x299A, ///< 6.2.3 20726
        SMSG_LFG_OFFER_CONTINUE                           = 0x29B3, ///< 6.2.3 20726
        SMSG_LFG_OPEN_FROM_GOSSIP                         = 0x0000, ///< (unused)
        SMSG_LFG_PARTY_INFO                               = 0x29B5, ///< 6.2.3 20726
        SMSG_LFG_PLAYER_INFO                              = 0x29B6, ///< 6.2.3 20726
        SMSG_LFG_PLAYER_REWARD                            = 0x29B7, ///< 6.2.3 20726
        SMSG_LFG_PROPOSAL_UPDATE                          = 0x29AA, ///< 6.2.3 20726
        SMSG_LFG_QUEUE_STATUS                             = 0x299E, ///< 6.2.3 20726
        SMSG_LFG_ROLE_CHECK_UPDATE                        = 0x299F, ///< 6.2.3 20726
        SMSG_LFG_ROLE_CHOSEN                              = 0x111B, ///< 6.2.3 20726
        SMSG_LFG_SEARCH_RESULT                            = 0x0000, ///< (unused)
        SMSG_LFG_SLOT_INVALID                             = 0x29AE, ///< (unused)
        SMSG_LFG_TELEPORT_DENIED                          = 0x29B1, ///< 6.2.3 20726
        SMSG_LFG_UPDATE_LIST                              = 0x0000, ///<
        SMSG_LFG_UPDATE_PARTY                             = 0x0000,
        SMSG_LFG_UPDATE_PLAYER                            = 0x0000,
        SMSG_LFG_UPDATE_SEARCH                            = 0x0000,
        SMSG_LFG_UPDATE_STATUS                            = 0x29A2, ///< 6.2.3 20726
        SMSG_LFG_UPDATE_STATUS_NONE                       = 0x0000,
        SMSG_UPDATE_DUNGEON_ENCOUNTER_FOR_LOOT            = 0x29AF,

        /// LFG List
        SMSG_LFG_LIST_JOIN_RESULT                         = 0x299B, ///< 6.2.3 20726
        SMSG_LFG_LIST_UPDATE_BLACKLIST                    = 0x29A7, ///< 6.2.3 20726
        SMSG_LFG_LIST_UPDATE_STATUS                       = 0x29A3, ///< 6.2.3 20726
        SMSG_LFG_LIST_SEARCH_RESULT                       = 0x110B, ///< 6.2.3 20726
        SMSG_LFG_LIST_APPLY_FOR_GROUP_RESULT              = 0x1143, ///< 6.2.3 20726
        SMSG_LFG_LIST_APPLICANT_LIST_UPDATE               = 0x1108, ///< 6.2.3 20726
        SMSG_LFG_LIST_APPLICANT_GROUP_INVITE              = 0x105F, ///< 6.2.3 20726
    #pragma endregion

    //////////////////////////////////////////////////////////////////////////
    /// Jam Client Garrison
    //////////////////////////////////////////////////////////////////////////
    #pragma region JamGarrison
        SMSG_GET_GARRISON_INFO_RESULT                                   = 0x286E, ///< 6.2.3 20779
        SMSG_GARRISON_PLOT_PLACED                                       = 0x286F, ///< 6.2.3 20779
        SMSG_GARRISON_PLOT_REMOVED                                      = 0x2870, ///< 6.2.3 20779
        SMSG_GARRISON_PLACE_BUILDING_RESULT                             = 0x2871, ///< 6.2.3 20779
        SMSG_GARRISON_BUILDING_REMOVED                                  = 0x2872, ///< 6.2.3 20779
        SMSG_GARRISON_LEARN_SPECIALIZATION_RESULT                       = 0x2873, ///< 6.2.3 20779
        SMSG_GARRISON_BUILDING_SET_ACTIVE_SPECIALIZATION_RESULT         = 0x2874, ///< 6.2.3 20779
        SMSG_GARRISON_LEARN_BLUEPRINT_RESULT                            = 0x2875, ///< 6.2.3 20779
        SMSG_GARRISON_BLUEPRINT_AND_SPECIALIZATION_DATA                 = 0x1491, ///< 6.2.3 20779
        SMSG_GARRISON_GET_BUILDINGS_DATA                                = 0x14B6, ///< 6.2.3 20779
        SMSG_GARRISON_REMOTE_INFO                                       = 0x2878, ///< 6.2.3 20779
        SMSG_GARRISON_BUILDING_ACTIVATED                                = 0x2879, ///< 6.2.3 20779
        SMSG_GARRISON_UPGRADE_RESULT                                    = 0x287B, ///< 6.2.3 20779
        SMSG_GARRISON_ADD_FOLLOWER_RESULT                               = 0x287C, ///< 6.2.3 20779
        SMSG_GARRISON_REMOVE_FOLLOWER_RESULT                            = 0x287D, ///< 6.2.3 20779
        SMSG_GARRISON_LIST_FOLLOWERS_CHEAT_RESULT                       = 0x287E,
        SMSG_GARRISON_UPDATE_FOLLOWER_ACTIVATION_COUNT                  = 0x1832, ///< 6.2.3 20779
        SMSG_GARRISON_UPDATE_FOLLOWER                                   = 0x1939, ///< 6.2.3 20779
        SMSG_GARRISON_FOLLOWER_CHANGED_XP                               = 0x288A, ///< 6.2.3 20779
        SMSG_GARRISON_FOLLOWER_CHANGED_ITEM_LEVEL                       = 0x288B, ///< 6.2.3 20779
        SMSG_GARRISON_ADD_MISSION_RESULT                                = 0x287F, ///< 6.2.3 20779
        SMSG_GARRISON_START_MISSION_RESULT                              = 0x2880, ///< 6.2.3 20779
        SMSG_GARRISON_COMPLETE_MISSION_RESULT                           = 0x2882, ///< 6.2.3 20779
        SMSG_GARRISON_MISSION_BONUS_ROLL_RESULT                         = 0x2885, ///< 6.2.3 20779
        SMSG_GARRISON_ASSIGN_FOLLOWER_TO_BUILDING_RESULT                = 0x2890, ///< 6.2.3 20779
        SMSG_GARRISON_REMOVE_FOLLOWER_FROM_BUILDING_RESULT              = 0x2891, ///< 6.2.3 20779
        SMSG_GARRISON_DELETE_RESULT                                     = 0x2897, ///< 6.2.3 20779
        SMSG_GARRISON_OPEN_ARCHITECT                                    = 0x2898, ///< 6.2.3 20779
        SMSG_GARRISON_OPEN_RECRUITMENT_NPC                              = 0x2894, ///< 6.2.3 20779
        SMSG_GARRISON_RECRUITMENT_FOLLOWERS_GENERATED                   = 0x2895, ///< 6.2.3 20779
        SMSG_GARRISON_RECRUIT_FOLLOWER_RESULT                           = 0x2896, ///< 6.2.3 20779
        SMSG_GARRISON_OPEN_MISSION_NPC                                  = 0x289A, ///< 6.2.3 20779
        SMSG_GARRISON_REQUEST_UPGRADEABLE_RESULT                        = 0x10BA, ///< 6.2.3 20779
        SMSG_GARRISON_OPEN_TRADESKILL_NPC                               = 0x2899, ///< 6.2.3 20779
        SMSG_GARRISON_SET_MISSION_NPC                                   = 0x159A, ///< 6.2.3 20779
        SMSG_GARRISON_FOLLOWER_DELETE_NOTIFY                            = 0x18B5, ///< 6.2.3 20779
    #pragma endregion

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// Low protocol
    //////////////////////////////////////////////////////////////////////////
    CMSG_HANDSHAKE                              = 0x4F57,
    SMSG_HANDSHAKE                              = 0x4F57,

    //////////////////////////////////////////////////////////////////////////
    /// Garrison
    //////////////////////////////////////////////////////////////////////////
    CMSG_GARRISON_CREATE_CHEAT                              = 0x0000,
    CMSG_GARRISON_DELETE_CHEAT                              = 0x0000,
    CMSG_GARRISON_SET_LEVEL_CHEAT                           = 0x0000,
    CMSG_GARRISON_PLACE_BUILDING_CHEAT                      = 0x0000,
    CMSG_GARRISON_REMOVE_BUILDING_CHEAT                     = 0x0000,
    CMSG_GARRISON_UPGRADE_BUILDING_CHEAT                    = 0x0000,
    CMSG_GARRISON_CANCEL_CONSTRUCTION                       = 0x3219, ///< 6.2.3 20726
    CMSG_GARRISON_LEARN_BUILDING_SPECIALIZATION_CHEAT       = 0x0000,
    CMSG_GARRISON_SET_ACTIVE_BUILDING_SPECIALIZATION        = 0x0000,
    CMSG_GARRISON_SET_ACTIVE_BUILDING_SPECIALIZATION_CHEAT  = 0x0000,
    CMSG_GET_GARRISON_INFO                                  = 0x320F, ///< 6.2.3 20726
    CMSG_GARRISON_LEARN_BLUEPRINT_CHEAT                     = 0x0000,
    CMSG_GARRISON_REQUEST_BUILDINGS                         = 0x0175, ///< 6.2.3 20779
    CMSG_GARRISON_PURCHASE_BUILDING                         = 0x3215, ///< 6.2.3 20779
    CMSG_GARRISON_SET_BUILDING_ACTIVE                       = 0x3216, ///< 6.2.3 20779
    CMSG_GARRISON_FORCE_BUILDING_ACTIVE                     = 0x0000,
    CMSG_GARRISON_PORT_CHEAT                                = 0x0000,
    CMSG_GARRISON_ADD_FOLLOWER_XPCHEAT                      = 0x0000,
    CMSG_GARRISON_SET_FOLLOWER_ITEM_LEVEL_CHEAT             = 0x0000,
    CMSG_GARRISON_ASSIGN_FOLLOWER_TO_BUILDING               = 0x3227, ///< 6.2.3 20779
    CMSG_GARRISON_REMOVE_FOLLOWER_FROM_BUILDING             = 0x3228, ///< 6.2.3 20779
    CMSG_GARRISON_CHANGE_FOLLOWER_ACTIVATION_STATE          = 0x08B0, ///< 6.2.3 20779
    CMSG_SHOW_GARRISON_TRANSFER                             = 0x0000,
    CMSG_GARRISON_ADD_UNIQUE_FOLLOWER_CHEAT                 = 0x0000,
    CMSG_GARRISON_REMOVE_FOLLOWER_CHEAT                     = 0x0000,
    CMSG_GARRISON_LIST_FOLLOWERS_CHEAT                      = 0x0000,
    CMSG_GARRISON_ADD_MISSION_CHEAT                         = 0x0000,
    CMSG_GARRISON_START_MISSION                             = 0x3253, ///< 6.2.3 20779
    CMSG_GARRISON_COMPLETE_MISSION                          = 0x3254, ///< 6.2.3 20779
    CMSG_GARRISON_MISSION_BONUS_ROLL                        = 0x3256, ///< 6.2.3 20779
    CMSG_GARRISON_GENERATE_RECRUITS                         = 0x322A, ///< 6.2.3 20779
    CMSG_GARRISON_SET_RECRUITMENT_PREFERENCES               = 0x322B, ///< 6.2.3 20779
    CMSG_GARRISON_RECRUIT_FOLLOWER                          = 0x322C, ///< 6.2.3 20779
    CMSG_GARRISON_REQUEST_UPGRADEABLE                       = 0x08ED, ///< 6.2.3 20779
    CMSG_UPGRADE_GARRISON                                   = 0x3208, ///< 6.2.3 20779
    CMSG_GARRISON_REQUEST_LANDING_PAGE_SHIPMENT_INFO        = 0x3235, ///< 6.2.3 20779
    CMSG_GARRISON_MISSION_NPC_HELLO                         = 0x08B1, ///< 6.2.3 20779
    CMSG_GET_SHIPMENT_INFO                                  = 0x00EA, ///< 6.2.3 20779
    CMSG_CREATE_SHIPMENT                                    = 0x3236, ///< 6.2.3 20779
    CMSG_REQUEST_SET_MISSION_NPC                            = 0x092D, ///< 6.2.3 20779

    /// Shipyard
    CMSG_GARRISON_FOLLOWER_RENAME                           = 0x0472, ///< 6.2.3 20726
    CMSG_GARRISON_DECOMISSION_SHIP                          = 0x0136, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// User Router
    //////////////////////////////////////////////////////////////////////////
    CMSG_LOG_STREAMING_ERROR                    = 0x36EA, ///< 6.2.3 20726
    CMSG_QUEUED_MESSAGES_END                    = 0x36E9, ///< 6.2.3 20726
    CMSG_LOG_DISCONNECT                         = 0x36E6, ///< 6.2.3 20726
    CMSG_PING                                   = 0x36E5, ///< 6.2.3 20726
    CMSG_AUTH_CONTINUED_SESSION                 = 0x36E4, ///< 6.2.3 20726
    CMSG_SUSPEND_TOKEN_RESPONSE                 = 0x36E7, ///< 6.2.3 20726
    CMSG_AUTH_SESSION                           = 0x36E3, ///< 6.2.3 20726
    CMSG_ENABLE_NAGLE                           = 0x36E8, ///< 6.2.3 20726
    CMSG_SUSPEND_COMMS_ACK                      = 0x36E2, ///< 6.2.3 20726
    CMSG_KEEP_ALIVE                             = 0x360F, ///< 6.2.3 20726
    CMSG_OBJECT_UPDATE_FAILED                   = 0x30FD, ///< 6.2.3 20726
    CMSG_OBJECT_UPDATE_RESCUED                  = 0x30FE, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// Character
    //////////////////////////////////////////////////////////////////////////
    CMSG_ENUM_CHARACTERS                        = 0x3568, ///< 6.2.3 20726
    CMSG_CREATE_CHARACTER                       = 0x35CA, ///< 6.2.3 20726
    CMSG_GENERATE_RANDOM_CHARACTER_NAME         = 0x3567, ///< 6.2.3 20726

    CMSG_CHAR_DELETE                            = 0x362B, ///< 6.2.3 20726
    CMSG_REORDER_CHARACTERS                     = 0x3569, ///< 6.2.3 20726
    CMSG_PLAYER_LOGIN                           = 0x356A, ///< 6.2.3 20726
    CMSG_VIOLENCE_LEVEL                         = 0x3101, ///< 6.2.3 20726
    CMSG_LOAD_SCREEN                            = 0x1428, ///< 6.2.3 20726
    CMSG_REQUEST_ACCOUNT_DATA                   = 0x3625, ///< 6.2.3 20726
    CMSG_UPDATE_ACCOUNT_DATA                    = 0x3626, ///< 6.2.3 20726
    CMSG_SET_DUNGEON_DIFFICULTY                 = 0x3612, ///< 6.2.3 20726
    CMSG_SET_RAID_DIFFICULTY                    = 0x366A, ///< 6.2.3 20726
    CMSG_AUTO_DECLINE_GUILD_INVITES             = 0x1D0A, ///< 6.2.3 20726
    CMSG_SHOWING_CLOAK                          = 0x3456, ///< 6.2.3 20726
    CMSG_SHOWING_HELM                           = 0x3455, ///< 6.2.3 20726
    CMSG_SET_ACTIVE_MOVER                       = 0x39AF, ///< 6.2.3 20726
    CMSG_LEARN_TALENTS                          = 0x3123, ///< 6.2.3 20726
    CMSG_AUTOEQUIP_ITEM                         = 0x1375, ///< 6.2.3 20726
    CMSG_SWAP_INV_ITEM                          = 0x391B, ///< 6.2.3 20726
    CMSG_SWAP_ITEM                              = 0x391A, ///< 6.2.3 20726
    CMSG_AUTOSTORE_BAG_ITEM                     = 0x161E, ///< 6.2.3 20726
    CMSG_REQUEST_PET_INFO                       = 0x3402, ///<
    CMSG_STAND_STATE_CHANGE                     = 0x3106, ///< 6.2.3 20726
    CMSG_BINDER_ACTIVATE                        = 0x3426, ///< 6.2.3 20726
    CMSG_REQUEST_FORCED_REACTIONS               = 0x3168, ///< 6.2.3 20726
    CMSG_DESTROY_ITEM                           = 0x31E0, ///< 6.2.3 20726
    CMSG_OPEN_ITEM                              = 0x3263, ///< 6.2.3 20726
    CMSG_SET_TITLE                              = 0x31D4, ///< 6.2.3 20726
    CMSG_PLAYED_TIME                            = 0x003D, ///< 6.2.3 20726
    CMSG_SAVE_EQUIPMENT_SET                     = 0x3477, ///< 6.2.3 20726
    CMSG_USE_EQUIPMENT_SET                      = 0x3913, ///< 6.2.3 20726
    CMSG_DELETE_EQUIPMENT_SET                   = 0x3478, ///< 6.2.3 20726
    CMSG_WHO                                    = 0x3611, ///< 6.2.3 20726
    CMSG_SOCKET_GEMS                            = 0x3453, ///< 6.2.3 20726
    CMSG_RESURRECT_RESPONSE                     = 0x3614, ///< 6.2.3 20726
    CMSG_QUERY_INSPECT_ACHIEVEMENTS             = 0x346F, ///< 6.2.3 20726
    CMSG_SPLIT_ITEM                             = 0x391C, ///< 6.2.3 20726
    CMSG_SET_PLAYER_DECLINED_NAMES              = 0x361A, ///< 6.2.3 20726
    CMSG_MOUNT_SET_FAVORITE                     = 0x35B8, ///< 6.2.3 20726
    CMSG_SORT_BAGS                              = 0x326B, ///< 6.2.3 20726
    CMSG_CHAR_RENAME                            = 0x05F0, ///< 6.2.3 20726
    CMSG_CHAR_CUSTOMIZE                         = 0x361E, ///< 6.2.3 20726
    CMSG_CHAR_RACE_OR_FACTION_CHANGE            = 0x3624, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// Bank
    //////////////////////////////////////////////////////////////////////////
    CMSG_BANKER_ACTIVATE                        = 0x3427, ///< 6.2.3 20726
    CMSG_AUTOBANK_ITEM                          = 0x3917, ///< 6.2.3 20726
    CMSG_AUTOSTORE_BANK_ITEM                    = 0x3916, ///< 6.2.3 20726
    CMSG_AUTOBANK_REAGENT                       = 0x3914, ///< 6.2.3 20779
    CMSG_AUTOSTORE_BANK_REAGENT                 = 0x3915, ///< 6.2.3 20779
    CMSG_BUY_BANK_SLOT                          = 0x3428, ///< 6.2.3 20726
    CMSG_BUY_REAGENT_BANK                       = 0x3429, ///< 6.2.3 20726
    CMSG_SORT_BANK_BAGS                         = 0x326C, ///< 6.2.3 20726
    CMSG_SORT_REAGENT_BANK_BAGS                 = 0x326D, ///< 6.2.3 20726
    CMSG_DEPOSIT_ALL_REAGENTS                   = 0x0C69, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// Auction House
    //////////////////////////////////////////////////////////////////////////
    CMSG_AUCTION_LIST_BIDDER_ITEMS              = 0x343A, ///< 6.2.3 20726
    CMSG_AUCTION_LIST_ITEMS                     = 0x3437, ///< 6.2.3 20726
    CMSG_AUCTION_LIST_OWNER_ITEMS               = 0x3439, ///< 6.2.3 20726
    CMSG_AUCTION_LIST_PENDING_SALES             = 0x343C, ///< 6.2.3 20726
    CMSG_AUCTION_PLACE_BID                      = 0x343B, ///< 6.2.3 20726
    CMSG_AUCTION_REMOVE_ITEM                    = 0x3436, ///< 6.2.3 20726
    CMSG_AUCTION_SELL_ITEM                      = 0x3435, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// Loot
    //////////////////////////////////////////////////////////////////////////
    CMSG_LOOT                                   = 0x096E, ///< 6.2.3 20726
    CMSG_LOOT_MONEY                             = 0x316E, ///< 6.2.3 20726
    CMSG_LOOT_ITEM                              = 0x316F, ///< 6.2.3 20726
    CMSG_LOOT_RELEASE                           = 0x3173, ///< 6.2.3 20726
    CMSG_LOOT_ROLL                              = 0x3174, ///< 6.2.3 20726
    CMSG_MASTER_LOOT_ITEM                       = 0x3170, ///< 6.2.3 20726
    CMSG_DO_MASTER_LOOT_ROLL                    = 0x3171, ///< 6.2.3 20726
    CMSG_SET_LOOT_SPECIALIZATION                = 0x34A5, ///< 6.2.3 20726
    CMSG_SET_LOOT_METHOD                        = 0x35CF, ///< 6.2.3 20726
    CMSG_OPT_OUT_OF_LOOT                        = 0x3460, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// Combat
    //////////////////////////////////////////////////////////////////////////
    CMSG_ATTACKSTOP                             = 0x0DA6, ///< 6.2.3 20726
    CMSG_ATTACKSWING                            = 0x0C2A, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// Duel
    //////////////////////////////////////////////////////////////////////////
    CMSG_DUEL_PROPOSED                          = 0x10EB, ///< 6.2.3 20726
    CMSG_DUEL_RESPONSE                          = 0x344B, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// Spell
    //////////////////////////////////////////////////////////////////////////
    CMSG_CAST_SPELL                             = 0x31E9, ///< 6.2.3 20726
    CMSG_CANCEL_CAST                            = 0x31EB, ///< 6.2.3 20726
    CMSG_USE_ITEM                               = 0x31E5, ///< 6.2.3 20726
    CMSG_CANCEL_AURA                            = 0x3126, ///< 6.2.3 20726
    CMSG_CANCEL_AUTO_REPEAT_SPELL               = 0x344F, ///< 6.2.3 20726
    CMSG_CANCEL_CHANNELLING                     = 0x31BF, ///< 6.2.3 20726
    CMSG_CANCEL_GROWTH_AURA                     = 0x31C4, ///< 6.2.3 20726
    CMSG_CANCEL_MOUNT_AURA                      = 0x31D5, ///< 6.2.3 20726
    CMSG_CANCEL_QUEUED_SPELL                    = 0x30FC, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// Cache
    //////////////////////////////////////////////////////////////////////////
    CMSG_DB_QUERY_BULK                          = 0x3566, ///< 6.2.3 20726
    CMSG_QUERY_CREATURE                         = 0x31C5, ///< 6.2.3 20726
    CMSG_NPC_TEXT_QUERY                         = 0x04E2, ///< 6.2.3 20726
    CMSG_NAME_QUERY                             = 0x01A4, ///< 6.2.3 20726
    CMSG_QUEST_QUERY                            = 0x08BD, ///< 6.2.3 20726
    CMSG_QUEST_POI_QUERY                        = 0x3641, ///< 6.2.3 20726
    CMSG_REALM_NAME_QUERY                       = 0x016C, ///< 6.2.3 20726
    CMSG_GAMEOBJECT_QUERY                       = 0x182D, ///< 6.2.3 20726
    CMSG_PETITION_QUERY                         = 0x050A, ///< 6.2.3 20726
    CMSG_QUERY_GUILD_INFO                       = 0x361D, ///< 6.2.3 20726
    CMSG_PAGE_TEXT_QUERY                        = 0x0C21, ///< 6.2.3 20726
    CMSG_ITEM_TEXT_QUERY                        = 0x3262, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// Interaction
    //////////////////////////////////////////////////////////////////////////
    CMSG_LOGOUT_REQUEST                         = 0x3440, ///< 6.2.3 20726
    CMSG_LOGOUT_CANCEL                          = 0x3441, ///< 6.2.3 20726
    CMSG_SET_ACTION_BUTTON                      = 0x35BC, ///< 6.2.3 20726
    CMSG_SET_ACTIONBAR_TOGGLES                  = 0x1D29, ///< 6.2.3 20726
    CMSG_SET_SELECTION                          = 0x348F, ///< 6.2.3 20726
    CMSG_SETSHEATHED                            = 0x0C5A, ///< 6.2.3 20726
    CMSG_GOSSIP_HELLO                           = 0x0A19, ///< 6.2.3 20726
    CMSG_GOSSIP_SELECT_OPTION                   = 0x3406, ///< 6.2.3 20726
    CMSG_TOGGLE_PVP                             = 0x31F7, ///< 6.2.3 20726
    CMSG_TUTORIAL                               = 0x366B, ///< 6.2.3 20726
    CMSG_SET_SPECIALIZATION                     = 0x3122, ///< 6.2.3 20726
    CMSG_SET_WATCHED_FACTION                    = 0x344A, ///< 6.2.3 20726
    CMSG_SET_FACTION_INACTIVE                   = 0x3449, ///< 6.2.3 20726
    CMSG_AREATRIGGER                            = 0x043D, ///< 6.2.3 20726
    CMSG_GAMEOBJECT_REPORT_USE                  = 0x1101, ///< 6.2.3 20726
    CMSG_GAMEOBJECT_USE                         = 0x0359, ///< 6.2.3 20726
    CMSG_SAVE_CUF_PROFILES                      = 0x3108, ///< 6.2.3 20726
    CMSG_SPELLCLICK                             = 0x150A, ///< 6.2.3 20726
    CMSG_REPOP_REQUEST                          = 0x348D, ///< 6.2.3 20726
    CMSG_RECLAIM_CORPSE                         = 0x3444, ///< 6.2.3 20726
    CMSG_QUERY_CORPSE_LOCATION_FROM_CLIENT      = 0x35EC, ///< 6.2.3 20726
    CMSG_QUERY_CORPSE_TRANSPORT                 = 0x35ED, ///< 6.2.3 20726
    CMSG_RETURN_TO_GRAVEYARD                    = 0x1509, ///< 6.2.3 20726
    CMSG_CLOSE_INTERACTION                      = 0x3405, ///< 6.2.3 20726
    CMSG_ITEM_REFUND_INFO                       = 0x1DA1, ///< 6.2.3 20726
    CMSG_FAR_SIGHT                              = 0x3450, ///< 6.2.3 20726
    CMSG_MOUNTSPECIAL_ANIM                      = 0x04F5, ///< 6.2.3 20726
    CMSG_OPENING_CINEMATIC                      = 0x34A9, ///< 6.2.3 20726
    CMSG_NEXT_CINEMATIC_CAMERA                  = 0x34AA, ///< 6.2.3 20726
    CMSG_COMPLETE_CINEMATIC                     = 0x34AB, ///< 6.2.3 20726
    CMSG_REQUEST_CEMETERY_LIST                  = 0x30F2, ///< 6.2.3 20726
    CMSG_TOTEM_DESTROYED                        = 0x3464, ///< 6.2.3 20726
    CMSG_CONFIRM_RESPEC_WIPE                    = 0x316C, ///< 6.2.3 20726
    CMSG_CANCEL_TRADE                           = 0x30DA, ///< 6.2.3 20726
    CMSG_SET_TRADE_CURRENCY                     = 0x30DE, ///< 6.2.3 20726
    CMSG_SET_TRADE_GOLD                         = 0x30DD, ///< 6.2.3 20726
    CMSG_SET_TRADE_ITEM                         = 0x30DB, ///< 6.2.3 20726
    CMSG_CLEAR_TRADE_ITEM                       = 0x30DC, ///< 6.2.3 20726
    CMSG_ACCEPT_TRADE                           = 0x30D8, ///< 6.2.3 20726
    CMSG_BUSY_TRADE                             = 0x30D6, ///< 6.2.3 20726
    CMSG_BEGIN_TRADE                            = 0x30D5, ///< 6.2.3 20726
    CMSG_IGNORE_TRADE                           = 0x30D7, ///< 6.2.3 20726
    CMSG_INITIATE_TRADE                         = 0x30D4, ///< 6.2.3 20726
    CMSG_UNACCEPT_TRADE                         = 0x30D9, ///< 6.2.3 20726
    CMSG_NEUTRAL_PLAYER_SELECT_FACTION          = 0x3139, ///< 6.2.3 20726
    CMSG_INSPECT                                = 0x3490, ///< 6.2.3 20726
    CMSG_INSPECT_HONOR_STATS                    = 0x1C86, ///< 6.2.3 20726
    CMSG_REQUEST_INSPECT_RATED_BG_STATS         = 0x1024, ///< 6.2.3 20726
    CMSG_TIME_SYNC_RESP                         = 0x119D, ///< 6.2.3 20726
    CMSG_UNLEARN_SKILL                          = 0x344D, ///< 6.2.3 20726
    CMSG_UNLEARN_SPECIALIZATION                 = 0x311D, ///< 6.2.3 20726
    CMSG_EMOTE                                  = 0x34A7, ///< 6.2.3 20726
    CMSG_SEND_TEXT_EMOTE                        = 0x33F9, ///< 6.2.3 20726
    CMSG_ALTER_APPEARANCE                       = 0x345F, ///< 6.2.3 20726
    CMSG_SELF_RES                               = 0x3497, ///< 6.2.3 20726
    CMSG_READ_ITEM                              = 0x3264, ///< 6.2.3 20726
    CMSG_COMPLETE_MOVIE                         = 0x3446, ///< 6.2.3 20726
    CMSG_SCENE_TRIGGER_EVENT                    = 0x3181, ///< 6.2.3 20726
    CMSG_GET_MIRRORIMAGE_DATA                   = 0x0461, ///< 6.2.3 20726
    CMSG_SHOW_TRADE_SKILL                       = 0x3650, ///< 6.2.3 20726
    CMSG_SCENE_PLAYBACK_CANCELED                = 0x3180, ///< 6.2.3 20726
    CMSG_REQUEST_RESEARCH_HISTORY               = 0x30E5, ///< 6.2.3 20726
    CMSG_SUMMON_RESPONSE                        = 0x35FA, ///< 6.2.3 20726
    CMSG_SET_FACTION_ATWAR                      = 0x1582, ///< 6.2.3 20726
    CMSG_UNSET_FACTION_ATWAR                    = 0x077D, ///< 6.2.3 20726
    CMSG_USE_CRITTER_ITEM                       = 0x319E, ///< 6.2.3 20779

    //////////////////////////////////////////////////////////////////////////
    /// Vehicles
    //////////////////////////////////////////////////////////////////////////
    CMSG_MOVE_SET_VEHICLE_REC_ID_ACK            = 0x398B, ///< 6.2.3 20726
    CMSG_PLAYER_VEHICLE_ENTER                   = 0x1CA9, ///< 6.2.3 20726
    CMSG_REQUEST_VEHICLE_EXIT                   = 0x3193, ///< 6.2.3 20726
    CMSG_REQUEST_VEHICLE_NEXT_SEAT              = 0x3194, ///< 6.2.3 20726
    CMSG_REQUEST_VEHICLE_PREV_SEAT              = 0x3195, ///< 6.2.3 20726
    CMSG_REQUEST_VEHICLE_SWITCH_SEAT            = 0x3196, ///< 6.2.3 20726
    CMSG_CHANGE_SEATS_ON_CONTROLLED_VEHICLE     = 0x1032, ///< 6.2.3 20726
    CMSG_EJECT_PASSENGER                        = 0x3198, ///< 6.2.3 20726
    CMSG_DISMISS_CONTROLLED_VEHICLE             = 0x111E, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// Vendors
    //////////////////////////////////////////////////////////////////////////
    CMSG_LIST_INVENTORY                         = 0x3415, ///< 6.2.3 20726
    CMSG_REPAIR_ITEM                            = 0x3454, ///< 6.2.3 20726
    CMSG_BUYBACK_ITEM                           = 0x1906, ///< 6.2.3 20726
    CMSG_BUY_ITEM                               = 0x3417, ///< 6.2.3 20726
    CMSG_SELL_ITEM                              = 0x3416, ///< 6.2.3 20726
    CMSG_ITEM_REFUND                            = 0x0C1A, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// Taxi
    //////////////////////////////////////////////////////////////////////////
    CMSG_SET_TAXI_BENCHMARK_MODE                = 0x345D, ///< 6.2.3 20726
    CMSG_ENABLE_TAXI_NODE                       = 0x341D, ///< 6.2.3 20726
    CMSG_TAXI_QUERY_AVAILABLE_NODES             = 0x341E, ///< 6.2.3 20726
    CMSG_ACTIVATE_TAXI                          = 0x341F, ///< 6.2.3 20726
    CMSG_TAXI_NODE_STATUS_QUERY                 = 0x341C, ///< 6.2.3 20726
    CMSG_TAXI_REQUEST_EARLY_LANDING             = 0x3420, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// Quest
    //////////////////////////////////////////////////////////////////////////
    CMSG_QUESTGIVER_HELLO                       = 0x035A, ///< 6.2.3 20726
    CMSG_QUEST_GIVER_STATUS_QUERY               = 0x3410, ///< 6.2.3 20726
    CMSG_QUESTGIVER_STATUS_MULTIPLE_QUERY       = 0x061E, ///< 6.2.3 20726
    CMSG_QUESTGIVER_QUERY_QUEST                 = 0x198A, ///< 6.2.3 20726
    CMSG_QUESTGIVER_COMPLETE_QUEST              = 0x0775, ///< 6.2.3 20726
    CMSG_QUESTGIVER_CHOOSE_REWARD               = 0x037E, ///< 6.2.3 20726
    CMSG_QUESTGIVER_ACCEPT_QUEST                = 0x005E, ///< 6.2.3 20726
    CMSG_QUESTGIVER_REQUEST_REWARD              = 0x118A, ///< 6.2.3 20726
    CMSG_QUEST_CONFIRM_ACCEPT                   = 0x3412, ///< 6.2.3 20726
    CMSG_QUESTLOG_REMOVE_QUEST                  = 0x033E, ///< 6.2.3 20726
    CMSG_PUSH_QUEST_TO_PARTY                    = 0x3413, ///< 6.2.3 20726
    CMSG_QUEST_PUSH_RESULT                      = 0x3414, ///< 6.2.3 20726
    CMSG_QUERY_QUEST_COMPLETION_NPCS            = 0x30F1, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// Account data
    //////////////////////////////////////////////////////////////////////////
    CMSG_GET_UNDELETE_CHARACTER_COOLDOWN_STATUS = 0x366E, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// Chat
    //////////////////////////////////////////////////////////////////////////
    /// Addon chat
    CMSG_CHAT_ADDON_MESSAGE_INSTANCE_CHAT       = 0x3775, ///< 6.2.3 20779
    CMSG_CHAT_ADDON_MESSAGE_WHISPER             = 0x3750, ///< 6.2.3 20779
    CMSG_CHAT_ADDON_MESSAGE_GUILD               = 0x3752, ///< 6.2.3 20779
    CMSG_CHAT_ADDON_MESSAGE_OFFICER             = 0x3754, ///< 6.2.3 20779
    CMSG_CHAT_ADDON_MESSAGE_RAID                = 0x3773, ///< 6.2.3 20779
    CMSG_CHAT_ADDON_MESSAGE_PARTY               = 0x3771, ///< 6.2.3 20779
    CMSG_CHAT_ADDON_MESSAGE_CHANNEL             = 0x374E, ///< 6.2.3 20779
    CMSG_CHAT_REGISTER_ADDON_PREFIXES           = 0x374B, ///< 6.2.3 20779
    CMSG_CHAT_UNREGISTER_ALL_ADDON_PREFIXES     = 0x374C, ///< 6.2.3 20779

    /// Chat
    CMSG_CHAT_MESSAGE_RAID_WARNING              = 0x3776, ///< 6.2.3 20726
    CMSG_CHAT_MESSAGE_PARTY                     = 0x3770, ///< 6.2.3 20726
    CMSG_CHAT_MESSAGE_YELL                      = 0x376F, ///< 6.2.3 20726
    CMSG_CHAT_MESSAGE_SAY                       = 0x376D, ///< 6.2.3 20726
    CMSG_CHAT_MESSAGE_OFFICER                   = 0x3753, ///< 6.2.3 20726
    CMSG_CHAT_MESSAGE_EMOTE                     = 0x376E, ///< 6.2.3 20726
    CMSG_CHAT_MESSAGE_AFK                       = 0x3755, ///< 6.2.3 20726
    CMSG_CHAT_MESSAGE_DND                       = 0x3756, ///< 6.2.3 20726
    CMSG_CHAT_MESSAGE_GUILD                     = 0x3751, ///< 6.2.3 20726
    CMSG_CHAT_MESSAGE_RAID                      = 0x3772, ///< 6.2.3 20726
    CMSG_CHAT_MESSAGE_WHISPER                   = 0x374F, ///< 6.2.3 20726
    CMSG_CHAT_MESSAGE_CHANNEL                   = 0x374D, ///< 6.2.3 20726

    /// Channel
    CMSG_JOIN_CHANNEL                           = 0x0BF6, ///< 6.2.3 20726
    CMSG_CHANNEL_ANNOUNCEMENTS                  = 0x0BBE, ///< 6.2.3 20726
    CMSG_CHANNEL_BAN                            = 0x0FFA, ///< 6.2.3 20726
    CMSG_CHANNEL_DISPLAY_LIST                   = 0x039E, ///< 6.2.0 19173
    CMSG_CHANNEL_INVITE                         = 0x07DE, ///< 6.2.3 20726
    CMSG_CHANNEL_KICK                           = 0x12B6, ///< 6.2.3 20726
    CMSG_CHANNEL_LIST                           = 0x139D, ///< 6.2.3 20726
    CMSG_CHANNEL_MODERATOR                      = 0x13B1, ///< 6.2.3 20726
    CMSG_CHANNEL_MUTE                           = 0x1295, ///< 6.2.3 20726
    CMSG_CHANNEL_OWNER                          = 0x0EFE, ///< 6.2.3 20726
    CMSG_CHANNEL_PASSWORD                       = 0x16B2, ///< 6.2.3 20726
    CMSG_CHANNEL_SET_OWNER                      = 0x13D2, ///< 6.2.3 20726
    CMSG_CHANNEL_SILENCE_ALL                    = 0x13DE, ///< 6.2.3 20726
    CMSG_CHANNEL_SILENCE_VOICE                  = 0x02F1, ///< 6.2.3 20726
    CMSG_CHANNEL_UNBAN                          = 0x0FB1, ///< 6.2.3 20726
    CMSG_CHANNEL_UNMODERATOR                    = 0x13F1, ///< 6.2.3 20726
    CMSG_CHANNEL_UNMUTE                         = 0x03DD, ///< 6.2.3 20726
    CMSG_CHANNEL_UNSILENCE_ALL                  = 0x02D2, ///< 6.2.3 20726
    CMSG_CHANNEL_UNSILENCE_VOICE                = 0x0AF9, ///< 6.2.3 20726
    CMSG_CHANNEL_VOICE_OFF                      = 0x0EDE, ///< 6.2.3 20726
    CMSG_CHANNEL_VOICE_ON                       = 0x1A96, ///< 6.2.3 20726
    CMSG_DECLINE_CHANNEL_INVITE                 = 0x0BF5, ///< 6.2.3 20726
    CMSG_LEAVE_CHANNEL                          = 0x0BF1, ///< 6.2.3 20726
    CMSG_SET_ACTIVE_VOICE_CHANNEL               = 0x35DC, ///< 6.2.3 20726


    //////////////////////////////////////////////////////////////////////////
    /// Movement
    //////////////////////////////////////////////////////////////////////////
    /// Start
    CMSG_MOVE_START_FORWARD                     = 0x3962, ///< 6.2.3 20726
    CMSG_MOVE_START_TURN_LEFT                   = 0x3969, ///< 6.2.3 20726
    CMSG_MOVE_START_TURN_RIGHT                  = 0x396A, ///< 6.2.3 20726
    CMSG_MOVE_START_BACKWARD                    = 0x3963, ///< 6.2.3 20726
    CMSG_MOVE_START_STRAFE_LEFT                 = 0x3965, ///< 6.2.3 20726
    CMSG_MOVE_START_STRAFE_RIGHT                = 0x3966, ///< 6.2.3 20726
    CMSG_MOVE_START_ASCEND                      = 0x399E, ///< 6.2.3 20726
    CMSG_MOVE_START_DESCEND                     = 0x39A5, ///< 6.2.3 20726
    CMSG_MOVE_START_PITCH_UP                    = 0x396C, ///< 6.2.3 20726
    CMSG_MOVE_START_PITCH_DOWN                  = 0x396D, ///< 6.2.3 20726
    CMSG_MOVE_START_SWIM                        = 0x3976, ///< 6.2.3 20726

    /// Misc
    CMSG_MOVE_JUMP                              = 0x3968, ///< 6.2.3 20726
    CMSG_MOVE_FALL_LAND                         = 0x3975, ///< 6.2.3 20726
    CMSG_WORLD_PORT_RESPONSE                    = 0x3578, ///< 6.2.3 20726
    CMSG_MOVE_TIME_SKIPPED                      = 0x3991, ///< 6.2.3 20726
    CMSG_MOVE_SPLINE_DONE                       = 0x398F, ///< 6.2.3 20726

    /// Update
    CMSG_MOVE_HEARTBEAT                         = 0x3987, ///< 6.2.3 20726
    CMSG_MOVE_SET_FACING                        = 0x3980, ///< 6.2.3 20726
    CMSG_MOVE_SET_PITCH                         = 0x3981, ///< 6.2.3 20726
    CMSG_MOVE_SET_RUN_MODE                      = 0x396F, ///< 6.2.3 20726
    CMSG_MOVE_SET_WALK_MODE                     = 0x3970, ///< 6.2.3 20726
    CMSG_MOVE_TELEPORT_ACK                      = 0x3974, ///< 6.2.3 20726
    CMSG_MOVE_CHNG_TRANSPORT                    = 0x1412, ///< 6.2.3 20726

    /// Stop
    CMSG_MOVE_STOP                              = 0x3964, ///< 6.2.3 20726
    CMSG_MOVE_STOP_TURN                         = 0x396B, ///< 6.2.3 20726
    CMSG_MOVE_STOP_STRAFE                       = 0x3967, ///< 6.2.3 20726
    CMSG_MOVE_STOP_SWIM                         = 0x3977, ///< 6.2.3 20726
    CMSG_MOVE_STOP_ASCEND                       = 0x399F, ///< 6.2.3 20726
    CMSG_MOVE_STOP_PITCH                        = 0x396E, ///< 6.2.3 20726

    /// ACK
    CMSG_MOVE_FORCE_RUN_SPEED_CHANGE_ACK         = 0x3982, ///< 6.2.3 20726
    CMSG_MOVE_FORCE_RUN_BACK_SPEED_CHANGE_ACK    = 0x3983, ///< 6.2.3 20726
    CMSG_MOVE_FORCE_WALK_SPEED_CHANGE_ACK        = 0x3996, ///< 6.2.3 20726
    CMSG_MOVE_FORCE_SWIM_SPEED_CHANGE_ACK        = 0x3984, ///< 6.2.3 20726
    CMSG_MOVE_FORCE_SWIM_BACK_SPEED_CHANGE_ACK   = 0x3997, ///< 6.2.3 20726
    CMSG_MOVE_FORCE_FLIGHT_SPEED_CHANGE_ACK      = 0x39A2, ///< 6.2.3 20726
    CMSG_MOVE_FORCE_FLIGHT_BACK_SPEED_CHANGE_ACK = 0x39A3, ///< 6.2.3 20726
    CMSG_MOVE_FORCE_TURN_RATE_CHANGE_ACK         = 0x3998, ///< 6.2.3 20726
    CMSG_MOVE_FORCE_PITCH_RATE_CHANGE_ACK        = 0x39A7, ///< 6.2.3 20726
    CMSG_MOVE_KNOCK_BACK_ACK                     = 0x3989, ///< 6.2.3 20726
    CMSG_MOVE_SET_CAN_FLY_ACK                    = 0x399C, ///< 6.2.3 20726
    CMSG_MOVE_FEATHER_FALL_ACK                   = 0x3992, ///< 6.2.3 20726
    CMSG_MOVE_WATER_WALK_ACK                     = 0x3993, ///< 6.2.3 20726
    CMSG_MOVE_HOVER_ACK                          = 0x398A, ///< 6.2.3 20726
    CMSG_MOVE_APPLY_MOVEMENT_FORCE_ACK           = 0x398C, ///< 6.2.3 20779
    CMSG_MOVE_REMOVE_MOVEMENT_FORCE_ACK          = 0x398D, ///< 6.2.3 20779

    //////////////////////////////////////////////////////////////////////////
    /// Group
    //////////////////////////////////////////////////////////////////////////
    CMSG_PARTY_INVITE                           = 0x3581, ///< 6.2.3 20726
    CMSG_PARTY_INVITE_RESPONSE                  = 0x3582, ///< 6.2.3 20726
    CMSG_LEAVE_GROUP                            = 0x35D0, ///< 6.2.3 20726
    CMSG_PARTY_UNINVITE                         = 0x35CE, ///< 6.2.3 20726
    CMSG_SET_PARTY_LEADER                       = 0x35D1, ///< 6.2.3 20726
    CMSG_SET_ROLE                               = 0x3556, ///< 6.2.3 20726
    CMSG_MINIMAP_PING                           = 0x35D2, ///< 6.2.3 20726
    CMSG_RANDOM_ROLL                            = 0x35DB, ///< 6.2.3 20726
    CMSG_UPDATE_RAID_TARGET                     = 0x35D7, ///< 6.2.3 20726
    CMSG_CONVERT_RAID                           = 0x35D5, ///< 6.2.3 20726
    CMSG_DO_READY_CHECK                         = 0x35BA, ///< 6.2.3 20726
    CMSG_READY_CHECK_RESPONSE                   = 0x35BB, ///< 6.2.3 20726
    CMSG_INITIATE_ROLE_POLL                     = 0x3557, ///< 6.2.3 20726
    CMSG_REQUEST_RAID_INFO                      = 0x3655, ///< 6.2.3 20726
    CMSG_SET_EVERYONE_IS_ASSISTANT              = 0x359D, ///< 6.2.3 20726
    CMSG_CLEAR_RAID_MARKER                      = 0x311E, ///< 6.2.3 20726
    CMSG_GROUP_ASSISTANT_LEADER                 = 0x04BB, ///< 6.2.3 20726
    CMSG_GROUP_ASSIGNMENT                       = 0x1074, ///< 6.2.3 20726
    CMSG_GROUP_CHANGE_SUB_GROUP                 = 0x11B8, ///< 6.2.3 20726
    CMSG_GROUP_REQUEST_JOIN_UPDATES             = 0x0570, ///< 6.2.3 20726
    CMSG_GROUP_SWAP_SUB_GROUP                   = 0x05EC, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// Friend
    //////////////////////////////////////////////////////////////////////////
    CMSG_SEND_CONTACT_LIST                      = 0x365D, ///< 6.2.3 20726
    CMSG_ADD_FRIEND                             = 0x365E, ///< 6.2.3 20726
    CMSG_ADD_IGNORE                             = 0x3662, ///< 6.2.3 20726
    CMSG_SET_CONTACT_NOTES                      = 0x3660, ///< 6.2.3 20726
    CMSG_DEL_FRIEND                             = 0x365F, ///< 6.2.3 20726
    CMSG_DEL_IGNORE                             = 0x3663, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// Petition
    //////////////////////////////////////////////////////////////////////////
    CMSG_OFFER_PETITION                         = 0x3640, ///< 6.2.3 20726
    CMSG_PETITION_BUY                           = 0x3432, ///< 6.2.3 20726
    CMSG_PETITION_DECLINE                       = 0x1D86, ///< 6.2.3 20726
    CMSG_PETITION_RENAME                        = 0x1133, ///< 6.2.3 20726
    CMSG_PETITION_SHOWLIST                      = 0x0779, ///< 6.2.3 20726
    CMSG_PETITION_SHOW_SIGNATURES               = 0x3433, ///< 6.2.3 20726
    CMSG_PETITION_SIGN                          = 0x0679, ///< 6.2.3 20726
    CMSG_TURN_IN_PETITION                       = 0x349B, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// Pet
    //////////////////////////////////////////////////////////////////////////
    CMSG_PET_NAME_QUERY                         = 0x0569, ///< 6.2.3 20726
    CMSG_PET_RENAME                             = 0x3615, ///< 6.2.3 20726
    CMSG_PET_ABANDON                            = 0x33FF, ///< 6.2.3 20726
    CMSG_PET_ACTION                             = 0x33FD, ///< 6.2.3 20726
    CMSG_PET_CANCEL_AURA                        = 0x3400, ///< 6.2.3 20726
    CMSG_PET_CAST_SPELL                         = 0x31E8, ///< 6.2.3 20726
    CMSG_PET_SET_ACTION                         = 0x33FC, ///< 6.2.3 20726
    CMSG_PET_STOP_ATTACK                        = 0x33FE, ///< 6.2.3 20726
    CMSG_LEARN_PET_SPECIALIZATION_GROUP         = 0x3124, ///< 6.2.3 20726
    CMSG_LIST_STABLE_PETS                       = 0x0456, ///< 6.2.3 20726
    CMSG_SET_PET_SLOT                           = 0x30E6, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// Battlegrounds
    //////////////////////////////////////////////////////////////////////////
    CMSG_BATTLEMASTER_JOIN                      = 0x3489, ///< 6.2.3 20726
    CMSG_BATTLEMASTER_JOIN_ARENA                = 0x348A, ///< 6.2.3 20726
    CMSG_BATTLEMASTER_JOIN_ARENA_SKIRMISH       = 0x1DA9, ///< 6.2.3 20726
    CMSG_JOIN_RATED_BATTLEGROUND                = 0x30F4, ///< 6.2.3 20726
    CMSG_BATTLEFIELD_PORT                       = 0x348C, ///< 6.2.3 20726
    CMSG_REQUEST_BATTLEFIELD_STATUS             = 0x355C, ///< 6.2.3 20726
    CMSG_BATTLEFIELD_REQUEST_SCORE_DATA         = 0x0075, ///< 6.2.3 20726
    CMSG_REQUEST_PVP_REWARDS                    = 0x310E, ///< 6.2.3 20726
    CMSG_REQUEST_PVP_OPTIONS_ENABLED            = 0x1038, ///< 6.2.3 20726
    CMSG_QUERY_COUNTDOWN_TIMER                  = 0x3121, ///< 6.2.3 20726
    CMSG_REQUEST_CONQUEST_FORMULA_CONSTANTS     = 0x31FF, ///< 6.2.3 20726
    CMSG_LEAVE_BATTLEFIELD                      = 0x0429, ///< 6.2.3 20726
    CMSG_SPIRIT_HEALER_ACTIVATE                 = 0x3423, ///< 6.2.3 20726
    CMSG_AREA_SPIRIT_HEALER_QUERY               = 0x3424, ///< 6.2.3 20726
    CMSG_AREA_SPIRIT_HEALER_QUEUE               = 0x3425, ///< 6.2.3 20726
    CMSG_BATTLEFIELD_MGR_QUEUE_REQUEST          = 0x0846, ///< 6.2.3 20726
    CMSG_BATTLEFIELD_MGR_QUEUE_INVITE_RESPONSE  = 0x00E8, ///< 6.2.3 20726
    CMSG_BATTLEFIELD_MGR_QUEUE_EXIT_REQUEST     = 0x10BF, ///< 6.2.3 20726
    CMSG_BATTLEFIELD_MGR_ENTRY_INVITE_RESPONSE  = 0x04B4, ///< 6.2.3 20726
    CMSG_BATTLEFIELD_LIST                       = 0x30FB, ///< 6.2.3 20726
    CMSG_REQUEST_RATED_BATTLEFIELD_INFO         = 0x3564, ///< 6.2.3 20726
    CMSG_START_WAR_GAME                         = 0x355E, ///< 6.2.3 20726
    CMSG_ACCEPT_WARGAME_INVITE                  = 0x3560, ///< 6.2.3 20726
    CMSG_REPORT_PVP_AFK                         = 0x1D09, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// Guild
    //////////////////////////////////////////////////////////////////////////
    CMSG_GUILD_INVITE_BY_NAME                      = 0x3586, ///< 6.2.3 20726
    CMSG_ACCEPT_GUILD_INVITE                       = 0x357B, ///< 6.2.3 20726
    CMSG_GUILD_DECLINE_INVITATION                  = 0x2FDE, ///< 6.2.3 20726
    CMSG_GUILD_OFFICER_REMOVE_MEMBER               = 0x2FE1, ///< 6.2.3 20726
    CMSG_GUILD_SET_GUILD_MASTER                    = 0x3653, ///< 6.2.3 20726
    CMSG_GUILD_LEAVE                               = 0x2FE0, ///< 6.2.3 20726
    CMSG_GUILD_DELETE                              = 0x2FE6, ///< 6.2.3 20726
    CMSG_GUILD_UPDATE_MOTD_TEXT                    = 0x2FF2, ///< 6.2.3 20726
    CMSG_GUILD_UPDATE_INFO_TEXT                    = 0x2FF3, ///< 6.2.3 20726
    CMSG_GUILD_GET_RANKS                           = 0x2FEB, ///< 6.2.3 20726
    CMSG_GUILD_ADD_RANK                            = 0x2FE2, ///< 6.2.3 20726
    CMSG_GUILD_DELETE_RANK                         = 0x2FE3, ///< 6.2.3 20726
    CMSG_GUILD_SET_RANK_PERMISSIONS                = 0x2FE5, ///< 6.2.3 20726
    CMSG_GUILD_SHIFT_RANK                          = 0x2FE4, ///< 6.2.3 20726
    CMSG_GUILD_ASSIGN_MEMBER_RANK                  = 0x2FDD, ///< 6.2.3 20726
    CMSG_GUILD_GET_ROSTER                          = 0x2FF1, ///< 6.2.3 20726
    CMSG_GUILD_BANK_ACTIVATE                       = 0x342A, ///< 6.2.3 20726
    CMSG_GUILD_BANK_BUY_TAB                        = 0x342D, ///< 6.2.3 20726
    CMSG_GUILD_BANK_DEPOSIT_MONEY                  = 0x342F, ///< 6.2.3 20726
    CMSG_GUILD_BANK_LOG_QUERY                      = 0x3000, ///< 6.2.3 20726
    CMSG_GUILD_BANK_REMAINING_WITHDRAW_MONEY_QUERY = 0x3001, ///< 6.2.3 20726
    CMSG_GUILD_BANK_QUERY_TAB                      = 0x342C, ///< 6.2.3 20726
    CMSG_GUILD_BANK_TEXT_QUERY                     = 0x3005, ///< 6.2.3 20726
    CMSG_GUILD_BANK_SWAP_ITEMS                     = 0x342B, ///< 6.2.3 20726
    CMSG_GUILD_BANK_UPDATE_TAB                     = 0x342E, ///< 6.2.3 20726
    CMSG_GUILD_BANK_WITHDRAW_MONEY                 = 0x3430, ///< 6.2.3 20726
    CMSG_GUILD_BANK_SET_TAB_TEXT                   = 0x3004, ///< 6.2.3 20726
    CMSG_GUILD_GET_ACHIEVEMENT_MEMBERS             = 0x2FEF, ///< (unused)
    CMSG_GUILD_SET_FOCUSED_ACHIEVEMENT             = 0x2FEE, ///< 6.2.3 20726
    CMSG_GUILD_SET_ACHIEVEMENT_TRACKING            = 0x2FED, ///< (unused)
    CMSG_GUILD_SET_MEMBER_NOTE                     = 0x2FF0, ///< 6.2.3 20726
    CMSG_GUILD_CHALLENGE_UPDATE_REQUEST            = 0x2FF9, ///< 6.2.3 20726
    CMSG_REQUEST_GUILD_PARTY_STATE                 = 0x3120, ///< 6.2.3 20726
    CMSG_REQUEST_GUILD_REWARDS_LIST                = 0x311F, ///< 6.2.3 20726
    CMSG_GUILD_REPLACE_GUILD_MASTER                = 0x3006, ///< 6.2.3 20726
    CMSG_GUILD_CHANGE_NAME_REQUEST                 = 0x2FFC, ///<  (unused)
    CMSG_GUILD_PERMISSIONS_QUERY                   = 0x3002, ///< 6.2.3 20726
    CMSG_GUILD_EVENT_LOG_QUERY                     = 0x3003, ///< 6.2.3 20726
    CMSG_GUILD_NEWS_UPDATE_STICKY                  = 0x2FEC, ///< 6.2.3 20726
    CMSG_GUILD_QUERY_NEWS                          = 0x2FEA, ///< 6.2.3 20726
    CMSG_QUERY_GUILD_MEMBERS_FOR_RECIPE            = 0x0000, ///< (unused)
    CMSG_QUERY_GUILD_MEMBER_RECIPES                = 0x0000, ///< (unused)
    CMSG_QUERY_GUILD_RECIPES                       = 0x019A, ///< 6.2.3 20726
    CMSG_PLAYER_SAVE_GUILD_EMBLEM                  = 0x1402, ///< 6.2.3 20726

    /// Guild finding
    CMSG_LF_GUILD_ADD_RECRUIT                      = 0x35A3, ///< 6.2.3 20726
    CMSG_LF_GUILD_BROWSE                           = 0x35A5, ///< 6.2.3 20726
    CMSG_LF_GUILD_DECLINE_RECRUIT                  = 0x2FF6, ///< 6.2.3 20726
    CMSG_LF_GUILD_GET_APPLICATIONS                 = 0x2FF7, ///< 6.2.3 20726
    CMSG_LF_GUILD_GET_RECRUITS                     = 0x2FF5, ///< 6.2.3 20726
    CMSG_LF_GUILD_POST_REQUEST                     = 0x049D, ///< 6.2.3 20726
    CMSG_LF_GUILD_REMOVE_RECRUIT                   = 0x2FF8, ///< 6.2.3 20726
    CMSG_LF_GUILD_SET_GUILD_POST                   = 0x35A4, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// Battle pet opcodes
    //////////////////////////////////////////////////////////////////////////
    CMSG_QUERY_BATTLE_PET_NAME                     = 0x31CB,   ///< 6.2.3 20726

    CMSG_BATTLE_PETS_RECONVERT                     = 0x0000,   ///< Internal
    CMSG_BATTLE_PET_UPDATE_NOTIFY                  = 0x3145,   ///< 6.2.3 20726
    CMSG_BATTLE_PET_REQUEST_JOURNAL_LOCK           = 0x35AA,   ///< 6.2.3 20726
    CMSG_BATTLE_PET_REQUEST_JOURNAL                = 0x35AB,   ///< 6.2.3 20726
    CMSG_BATTLE_PET_DELETE_PET                     = 0x35AD,   ///< 6.2.3 20726
    CMSG_BATTLE_PET_DELETE_PET_CHEAT               = 0x35AC,   ///< 6.2.3 20726
    CMSG_BATTLE_PET_DELETE_JOURNAL                 = 0x0000,   ///< Internal
    CMSG_BATTLE_PET_MODIFY_NAME                    = 0x35AF,   ///< 6.2.3 20726
    CMSG_BATTLE_PET_SUMMON                         = 0x35B0,   ///< 6.2.3 20726
    CMSG_BATTLE_PET_SET_LEVEL                      = 0x0000,   ///< Internal
    CMSG_BATTLE_PET_SET_BATTLE_SLOT                = 0x35B3,   ///< 6.2.3 20726
    CMSG_BATTLE_PET_SET_COLLAR                     = 0x0000,   ///< Internal
    CMSG_BATTLE_PET_SET_FLAGS                      = 0x35B6,   ///< 6.2.3 20726
    CMSG_RESTORE_BATTLE_PETS_HEALTH                = 0x0000,   ///< Internal
    CMSG_ADD_BATTLE_PET                            = 0x0000,   ///< Internal
    CMSG_CHEAT_BATTLE_PET_SET_QUALITY              = 0x0000,   ///< Internal
    CMSG_CAGE_BATTLE_PET                           = 0x3154,   ///< 6.2.3 20726

    CMSG_JOIN_PET_BATTLE_QUEUE                     = 0x3143,   ///< 6.2.3 20726
    CMSG_LEAVE_PET_BATTLE_QUEUE                    = 0x3144,   ///< 6.2.3 20726
    CMSG_PET_BATTLE_REQUEST_WILD                   = 0x313F,   ///< 6.2.3 20726
    CMSG_PET_BATTLE_WILD_LOCATION_FAIL             = 0x0000,
    CMSG_PET_BATTLE_REQUEST_PVP                    = 0x3141,   ///< 6.2.3 20726
    CMSG_PET_BATTLE_REQUEST_UPDATE                 = 0x3142,   ///< 6.2.3 20726
    CMSG_PET_BATTLE_QUIT_NOTIFY                    = 0x3146,   ///< 6.2.3 20726
    CMSG_PET_BATTLE_FINAL_NOTIFY                   = 0x3147,   ///< 6.2.3 20726
    CMSG_PET_BATTLE_SCRIPT_ERROR_NOTIFY            = 0x3148,   ///< Internal
    CMSG_PET_BATTLE_QUEUE_PROPOSE_MATCH_RESULT     = 0x3184,   ///< 6.2.3 20726
    CMSG_PET_BATTLE_INPUT_FIRST_PET                = 0x0000,   ///< Internal
    CMSG_PET_BATTLE_INPUT                          = 0x35C7,   ///< 6.2.3 20726
    CMSG_PET_BATTLE_REPLACE_FRONT_PET              = 0x35C8,   ///< 6.2.3 20726
    CMSG_PET_BATTLE_DEBUG_QUEUE_DUMP               = 0x0000,   ///< Internal

    //////////////////////////////////////////////////////////////////////////
    /// Battle pay
    //////////////////////////////////////////////////////////////////////////
    CMSG_BATTLE_PAY_GET_PURCHASE_LIST              = 0x364D, ///< 6.2.3 20726
    CMSG_BATTLE_PAY_GET_PRODUCT_LIST_QUERY         = 0x00F0, ///< 6.2.3 20726
    CMSG_BATTLE_PAY_START_PURCHASE                 = 0x3680, ///< 6.2.3 20726
    CMSG_BATTLE_PAY_CONFIRM_PURCHASE_RESPONSE      = 0x3657, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// LFG
    //////////////////////////////////////////////////////////////////////////
    CMSG_DFGET_SYSTEM_INFO                         = 0x1138, ///< 6.2.3 20726
    CMSG_LFG_GET_PLAYER_INFO                       = 0x0000,
    CMSG_LFG_GET_STATUS                            = 0x11A7, ///< 6.2.3 20726
    CMSG_LFG_JOIN                                  = 0x11F8, ///< 6.2.3 20726
    CMSG_LFG_LEAVE                                 = 0x0424, ///< 6.2.3 20726
    CMSG_LFG_PROPOSAL_RESULT                       = 0x11B0, ///< 6.2.3 20726
    CMSG_LFG_SET_BOOT_VOTE                         = 0x05AC, ///< 6.2.3 20726
    CMSG_LFG_SET_COMMENT                           = 0x0000, ///< (unused)
    CMSG_DFSET_ROLES                               = 0x003B, ///< 6.2.3 20726
    CMSG_LFG_TELEPORT                              = 0x00A8, ///< 6.2.3 20726
    CMSG_SEARCH_LFG_JOIN                           = 0x0000, ///< (unused)
    CMSG_SEARCH_LFG_LEAVE                          = 0x0000, ///< (unused)
    CMSG_RESET_INSTANCES                           = 0x35F8, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// LFG LIST
    //////////////////////////////////////////////////////////////////////////
    CMSG_REQUEST_LFG_LIST_BLACKLIST                 = 0x31EF, ///< 6.2.3 20726
    CMSG_LFG_LIST_JOIN                              = 0x3589, ///< 6.2.3 20726
    CMSG_LFG_LIST_UPDATE_REQUEST                    = 0x358A, ///< 6.2.3 20726
    CMSG_LFG_LIST_LEAVE                             = 0x358B, ///< 6.2.3 20726
    CMSG_LFG_LIST_SEARCH                            = 0x358D, ///< 6.2.3 20726
    CMSG_LFG_LIST_APPLY_FOR_GROUP                   = 0x04F4, ///< 6.2.3 20726
    CMSG_LFG_LIST_INVITE_APPLICANT                  = 0x3591, ///< 6.2.3 20726
    CMSG_LFG_LIST_REMOVE_APPLICANT                  = 0x0470, ///< 6.2.3 20726
    CMSG_LFG_LIST_CANCEL_APPLICATION                = 0x358F, ///< 6.2.3 20726
    CMSG_LFG_LIST_INVITATION_ANSWER                 = 0x053F, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// Auction House
    //////////////////////////////////////////////////////////////////////////
    CMSG_AUCTION_HELLO                             = 0x1D0E, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// Trainers
    //////////////////////////////////////////////////////////////////////////
    CMSG_TRAINER_LIST                              = 0x3421, ///< 6.2.3 20726
    CMSG_TRAINER_BUY_SPELL                         = 0x3422, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// Void storage
    //////////////////////////////////////////////////////////////////////////
    CMSG_VOID_STORAGE_QUERY                        = 0x08E5, ///< 6.2.3 20726
    CMSG_VOID_STORAGE_TRANSFER                     = 0x311B, ///< 6.2.3 20726
    CMSG_VOID_STORAGE_UNLOCK                       = 0x0436, ///< 6.2.3 20726
    CMSG_VOID_SWAP_ITEM                            = 0x096A, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// Transmogrification
    //////////////////////////////////////////////////////////////////////////
    CMSG_TRANSMOGRIFY_ITEMS                        = 0x310F, ///< 6.2.0 19173

    //////////////////////////////////////////////////////////////////////////
    /// Mail
    //////////////////////////////////////////////////////////////////////////
    CMSG_GET_MAIL_LIST                             = 0x0859, ///< 6.2.3 20726
    CMSG_MAIL_CREATE_TEXT_ITEM                     = 0x34A1, ///< 6.2.3 20726
    CMSG_MAIL_DELETE                               = 0x3185, ///< 6.2.3 20726
    CMSG_MAIL_MARK_AS_READ                         = 0x34A0, ///< 6.2.3 20726
    CMSG_MAIL_RETURN_TO_SENDER                     = 0x35DF, ///< 6.2.3 20726
    CMSG_MAIL_TAKE_ITEM                            = 0x349E, ///< 6.2.3 20726
    CMSG_MAIL_TAKE_MONEY                           = 0x349D, ///< 6.2.3 20726
    CMSG_SEND_MAIL                                 = 0x3579, ///< 6.2.3 20726
    CMSG_QUERY_NEXT_MAIL_TIME                      = 0x349F, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// Time
    //////////////////////////////////////////////////////////////////////////
    CMSG_UITIME_REQUEST                            = 0x0567, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// GameMasters
    //////////////////////////////////////////////////////////////////////////
    CMSG_REPORT_BUG                                 = 0x10E8, ///< 6.2.3 20726
    CMSG_REPORT_SUGGESTION                          = 0x11BC, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// ToyBox
    //////////////////////////////////////////////////////////////////////////
    CMSG_ADD_NEW_TOY_TO_BOX                         = 0x05E1, ///< 6.2.3 20726
    CMSG_SET_FAVORITE_TOY                           = 0x1068, ///< 6.2.3 20726
    CMSG_USE_TOY                                    = 0x31E7, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// Calendarr
    //////////////////////////////////////////////////////////////////////////
    CMSG_CALENDAR_ADD_EVENT                         = 0x360D, ///< 6.2.3 20726
    CMSG_CALENDAR_COMPLAIN                          = 0x3609, ///< 6.2.3 20726
    CMSG_CALENDAR_COPY_EVENT                        = 0x3608, ///< 6.2.3 20726
    CMSG_CALENDAR_EVENT_INVITE                      = 0x3602, ///< 6.2.3 20726
    CMSG_CALENDAR_EVENT_MODERATOR_STATUS            = 0x3606, ///< 6.2.3 20726
    CMSG_CALENDAR_EVENT_REMOVE_INVITE               = 0x1067, ///< 6.2.3 20726
    CMSG_CALENDAR_EVENT_RSVP                        = 0x3604, ///< 6.2.3 20726
    CMSG_CALENDAR_EVENT_SIGNUP                      = 0x01A8, ///< 6.2.3 20726
    CMSG_CALENDAR_EVENT_STATUS                      = 0x3605, ///< 6.2.3 20726
    CMSG_CALENDAR_GET_CALENDAR                      = 0x0477, ///< 6.2.3 20726
    CMSG_CALENDAR_GET_EVENT                         = 0x3600, ///< 6.2.3 20726
    CMSG_CALENDAR_GET_NUM_PENDING                   = 0x360A, ///< 6.2.3 20726
    CMSG_CALENDAR_GUILD_FILTER                      = 0x3601, ///< 6.2.3 20726
    CMSG_CALENDAR_REMOVE_EVENT                      = 0x3607, ///< 6.2.3 20726
    CMSG_CALENDAR_UPDATE_EVENT                      = 0x360E, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// Challenges
    //////////////////////////////////////////////////////////////////////////
    CMSG_CHALLENGE_MODE_REQUEST_LEADERS             = 0x300D, ///< 6.2.3 20726
    CMSG_GET_CHALLENGE_MODE_REWARDS                 = 0x300F, ///< 6.2.3 20726
    CMSG_CHALLENGE_MODE_REQUEST_MAP_STATS           = 0x300C, ///< 6.2.3 20726
    CMSG_RESET_CHALLENGE_MODE                       = 0x3166, ///< 6.2.3 20779

    //////////////////////////////////////////////////////////////////////////
    /// BlackMarket
    //////////////////////////////////////////////////////////////////////////
    CMSG_BLACK_MARKET_OPEN                         = 0x3491, ///< 6.2.3 20726
    CMSG_BLACK_MARKET_REQUEST_ITEMS                = 0x3492, ///< 6.2.3 20726
    CMSG_BLACK_MARKET_PLACE_BID                    = 0x031A, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    /// Twitter
    //////////////////////////////////////////////////////////////////////////
    CMSG_REQUEST_TWITTER_STATUS                     = 0x0916, ///< 6.2.3 20726

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    // CMSG
    CMSG_ACCEPT_LEVEL_GRANT                             = 0x3463,
    CMSG_ADD_VOICE_IGNORE                               = 0x0000,
    CMSG_ARENA_TEAM_ACCEPT                              = 0x0000,
    CMSG_ARENA_TEAM_CREATE                              = 0x0000,
    CMSG_ARENA_TEAM_DECLINE                             = 0x0000,
    CMSG_ARENA_TEAM_DISBAND                             = 0x0000,
    CMSG_ARENA_TEAM_INVITE                              = 0x0000,
    CMSG_ARENA_TEAM_LEADER                              = 0x0000,
    CMSG_ARENA_TEAM_LEAVE                               = 0x0000,
    CMSG_ARENA_TEAM_QUERY                               = 0x0000,
    CMSG_ARENA_TEAM_REMOVE                              = 0x0000,
    CMSG_ARENA_TEAM_ROSTER                              = 0x0000,
    CMSG_AUTOEQUIP_GROUND_ITEM                          = 0x0000,
    CMSG_AUTOEQUIP_ITEM_SLOT                            = 0x0000,
    CMSG_AUTOSTORE_GROUND_ITEM                          = 0x0000,
    CMSG_BOT_DETECTED2                                  = 0x0000,
    CMSG_CANCEL_TEMP_ENCHANTMENT                        = 0x345C,
    CMSG_CHANGEPLAYER_DIFFICULTY                        = 0x0000,
    CMSG_CHAT_FILTERED                                  = 0x0000,
    CMSG_CHAT_IGNORED                                   = 0x0000,
    CMSG_COMMENTATOR_ENABLE                             = 0x3673,
    CMSG_COMMENTATOR_ENTER_INSTANCE                     = 0x3573,
    CMSG_COMMENTATOR_EXIT_INSTANCE                      = 0x3574,
    CMSG_COMMENTATOR_GET_MAP_INFO                       = 0x3571,
    CMSG_COMMENTATOR_GET_PARTY_INFO                     = 0x0000,
    CMSG_COMMENTATOR_GET_PLAYER_INFO                    = 0x3572,
    CMSG_COMMENTATOR_INSTANCE_COMMAND                   = 0x0000,
    CMSG_COMMENTATOR_SKIRMISH_QUEUE_COMMAND             = 0x0000,
    CMSG_COMMENTATOR_START_WARGAME                      = 0x356F,
    CMSG_COMPLAIN                                       = 0x0133,
    CMSG_CONNECT_TO_FAILED                              = 0x3552,
    CMSG_DANCE_QUERY                                    = 0x0000,
    CMSG_DEL_VOICE_IGNORE                               = 0x0000,
    CMSG_DISMISS_CRITTER                                = 0x3465,
    CMSG_FORCE_MOVE_ROOT_ACK                            = 0x0000,
    CMSG_FORCE_MOVE_UNROOT_ACK                          = 0x0000,
    CMSG_GAMESPEED_SET                                  = 0x0000,
    CMSG_GAMETIME_SET                                   = 0x0000,
    CMSG_GETDEATHBINDZONE                               = 0x0000,
    CMSG_GHOST                                          = 0x0000,
    CMSG_GRANT_LEVEL                                    = 0x3461,
    CMSG_HEARTH_AND_RESURRECT                           = 0x3474,
    CMSG_INSTANCE_LOCK_WARNING_RESPONSE                 = 0x0000,
    CMSG_MANEUVER_START                                 = 0x0000,
    CMSG_MEETINGSTONE_INFO                              = 0x0000,
    CMSG_MINIGAME_MOVE                                  = 0x0000,
    CMSG_MOVE_CHARM_TELEPORT_CHEAT                      = 0x3972,
    CMSG_MOVE_ENABLE_SWIM_TO_FLY_TRANS_ACK              = 0x3999,
    CMSG_MOVE_NOT_ACTIVE_MOVER                          = 0x0000,
    CMSG_MOVE_SET_RELATIVE_POSITION                     = 0x3973,
    CMSG_MOVE_TOGGLE_COLLISION_ACK                      = 0x0000,
    CMSG_NEW_SPELL_SLOT                                 = 0x0000,
    CMSG_PLAYER_DIFFICULTY_CHANGE                       = 0x0000,
    CMSG_PLAYER_LOGOUT                                  = 0x0000,
    CMSG_PLAY_DANCE                                     = 0x0000,
    CMSG_PVP_LOG_DATA                                   = 0x30F8,
    CMSG_QUERY_BATTLEFIELD_STATE                        = 0x0000,
    CMSG_QUERY_TIME                                     = 0x343F,
    CMSG_QUEST_NPC_QUERY                                = 0x0000,
    CMSG_REALM_SPLIT                                    = 0x0000,
    CMSG_REDIRECTION_AUTH_PROOF                         = 0x0000,
    CMSG_REQUEST_BATTLEPET_JOURNAL                      = 0x0000,
    CMSG_REQUEST_CATEGORY_COOLDOWNS                     = 0x30FA,
    CMSG_REQUEST_PARTY_MEMBER_STATS                     = 0x35DA,
    CMSG_REQUEST_RATED_BG_INFO                          = 0x0000,
    CMSG_REQUEST_RATED_BG_STATS                         = 0x0000,
    CMSG_RESET_FACTION_CHEAT                            = 0x0000,
    CMSG_SAVE_PLAYER                                    = 0x0000,
    CMSG_SEND_SOR_REQUEST_VIA_ADDRESS                   = 0x35A8,
    CMSG_SEND_SOR_REQUEST_VIA_BNET_ACCOUNT_ID           = 0x0000,
    CMSG_SERVERTIME                                     = 0x0000,
    CMSG_SETDEATHBINDPOINT                              = 0x0000,
    CMSG_SET_ALLOW_LOW_LEVEL_RAID1                      = 0x0000,
    CMSG_SET_ALLOW_LOW_LEVEL_RAID2                      = 0x0000,
    CMSG_SET_CURRENCY_FLAGS                             = 0x30E7,
    CMSG_SET_FACTION_CHEAT                              = 0x0000,
    CMSG_SET_LFG_COMMENT                                = 0x0000,
    CMSG_SET_PREFERED_CEMETERY                          = 0x0000,
    CMSG_SET_RELATIVE_POSITION                          = 0x0000,
    CMSG_SET_SAVED_INSTANCE_EXTEND                      = 0x3618,
    CMSG_SET_SKILL_CHEAT                                = 0x0000,
    CMSG_SHOW_ACCOUNT_ACHIEVEMENT                       = 0x0000,
    CMSG_START_QUEST                                    = 0x0000,
    CMSG_STOP_DANCE                                     = 0x0000,
    CMSG_SUBMIT_BUG                                     = 0x0000,
    CMSG_SUBMIT_COMPLAIN                                = 0x0000,
    CMSG_SUGGESTION_SUBMIT                              = 0x0000,
    CMSG_SUMMON_BATTLEPET_COMPANION                     = 0x0000,
    CMSG_SUSPEND_TOKEN                                  = 0x0000, ///<
    CMSG_SYNC_DANCE                                     = 0x0000,
    CMSG_TELEPORT_TO_UNIT                               = 0x35F1,
    CMSG_TIME_ADJUSTMENT_RESPONSE                       = 0x39B3, ///<
    CMSG_TIME_SYNC_RESP_FAILED                          = 0x0000, ///<
    CMSG_UNREGISTER_ALL_ADDON_PREFIXES                  = 0x0000,
    CMSG_UPDATE_MISSILE_TRAJECTORY                      = 0x39B6,
    CMSG_UPGRADE_ITEM                                   = 0x3187,
    CMSG_USED_FOLLOW                                    = 0x3103,
    CMSG_VOICE_SESSION_ENABLE                           = 0x3613,
    CMSG_WARDEN_DATA                                    = 0x356C,
    CMSG_WARGAME_ACCEPT                                 = 0x0000,
    CMSG_WARGAME_START                                  = 0x0000,
    CMSG_WHOIS                                          = 0x0000,
    CMSG_WORLD_TELEPORT                                 = 0x3562,
    CMSG_WRAP_ITEM                                      = 0x3912,
    CMSG_ARENA_2v2_STATS_REQUEST                        = 0x0000,
    CMSG_ARENA_3v3_STATS_REQUEST                        = 0x0000,

    CMSG_GMSURVEY_SUBMIT                            = 0x0000, ///< RIP ???
    CMSG_GMTICKET_GET_CASE_STATUS                   = 0x0000, ///< RIP ????
    CMSG_GMTICKET_SYSTEMSTATUS                      = 0x0000, ///< RIP ????
    CMSG_GM_REPORT_LAG                              = 0x0000, ///< RIP ????

    // SMSG
    SMSG_ACCOUNT_PROFILE                                = 0x0000,
    SMSG_ADD_BATTLENET_FRIEND_RESPONSE                  = 0x25DA,
    SMSG_AREA_SHARE_MAPPINGS_RESPONSE                   = 0x0000,
    SMSG_AREA_SHARE_INFO_RESPONSE                       = 0x0000,
    SMSG_BEASTMASTER_FAILED                             = 0x0000,
    SMSG_BONUS_ROLL_EMPTY                               = 0x25E3,
    SMSG_CHALLENGE_MODE_DELETE_LEADER_RESULT            = 0x0000,
    SMSG_CLEAR_ITEM_CHALLENGE_MODE_DATA                 = 0x0000,
    SMSG_CONSOLE_WRITE                                  = 0x25D1,
    SMSG_DISPLAY_PROMOTION                              = 0x25E9,
    SMSG_DISPLAY_PLAYER_CHOICE                          = 0x2622,
    SMSG_FORCE_OBJECT_RELINK                            = 0x25E8,
    SMSG_GHOST                                          = 0x0000,
    SMSG_GM_CHARACTER_SAVE_FAILURE                      = 0x0000,
    SMSG_GM_FREEZE_FAILURE                              = 0x0000,
    SMSG_GM_NAMED_POINTS                                = 0x0000,
    SMSG_GM_RESURRECT_FAILURE                           = 0x0000,
    SMSG_GM_REVEAL_TO                                   = 0x0000,
    SMSG_GM_SILENCE                                     = 0x0000,
    SMSG_IMMIGRANT_HOST_SEARCH_LOG                      = 0x0000,
    SMSG_LIST_TARGETS                                   = 0x0000,
    SMSG_MOVE_CHARACTER_CHEAT_FAILURE                   = 0x0000,
    SMSG_MOVE_CHARACTER_CHEAT_SUCCESS                   = 0x0000,
    SMSG_PENDING_RAID_LOCK                              = 0x26B2, //
    SMSG_PLAYER_NOT_FOUND_FAILURE                       = 0x0000,
    SMSG_REFRESH_COMPONENT                              = 0x25F9,
    SMSG_RESET_WEEKLY_CURRENCY                          = 0x24F2,
    SMSG_SCENE_OBJECT_EVENT                             = 0x257B,
    SMSG_SCENE_OBJECT_PET_BATTLE_FINISHED               = 0x2581,
    SMSG_SCENE_OBJECT_PET_BATTLE_FIRST_ROUND            = 0x257D,
    SMSG_SCENE_OBJECT_PET_BATTLE_FINAL_ROUND            = 0x2580,
    SMSG_SCENE_OBJECT_PET_BATTLE_ROUND_RESULT           = 0x257E,
    SMSG_SCENE_OBJECT_PET_BATTLE_REMPLACEMENTS_MADE     = 0x0000,
    SMSG_SERVER_INFO_QUERY_RESPONSE                     = 0x0000,
    SMSG_PROFILE_DATA_RESPONSE                          = 0x0000,
    SMSG_SET_ITEM_CHALLENGE_MODE_DATA                   = 0x0000,
    SMSG_SET_PROMOTION_RESPONSE                         = 0x0000,
    SMSG_SET_SERVER_WOW_TIME                            = 0x0000,
    SMSG_SHOW_ZONES_CHEAT_RESULT                        = 0x0000,
    SMSG_UPDATE_EXPANSION_LEVEL                         = 0x25E4,
    SMSG_ACCOUNT_INFO_RESPONSE                          = 0x0000,
    SMSG_AREA_TRIGGER_DENIED                            = 0x261E,
    SMSG_AREA_TRIGGER_MOVEMENT_UPDATE                   = 0x0000,
    SMSG_ARENA_ERROR                                    = 0x2693,
    SMSG_AVERAGE_ITEM_LEVEL_INFORM                      = 0x0000,
    SMSG_BATTLEGROUND_INFO_THROTTLED                    = 0x2523,
    SMSG_CAMERA_SHAKE                                   = 0x26E6,
    SMSG_CHARACTER_LOGIN_FAILED                         = 0x26C5,
    SMSG_CLEAR_BOSS_EMOTES                              = 0x2552,
    SMSG_COMBAT_EVENT_FAILED                            = 0x25F0,
    SMSG_COMMENTATOR_MAP_INFO                           = 0x26C7,
    SMSG_COMMENTATOR_PLAYER_INFO                        = 0x26C8,
    SMSG_COMMENTATOR_STATE_CHANGED                      = 0x26C6,
    SMSG_CUSTOM_LOAD_SCREEN                             = 0x2568,
    SMSG_DAMAGE_CALC_LOG                                = 0x277A,
    SMSG_DIFFERENT_INSTANCE_FROM_PARTY                  = 0x2507,
    SMSG_DISENCHANT_CREDIT                              = 0x2542,
    SMSG_DONT_AUTO_PUSH_SPELLS_TO_ACTION_BAR            = 0x257A,
    SMSG_DUMP_RIDE_TICKETS_RESPONSE                     = 0x0000,
    SMSG_FAILED_PLAYER_CONDITION                        = 0x2567,
    SMSG_GAMEOBJECT_RESET_STATE                         = 0x0000,
    SMSG_GAME_SPEED_SET                                 = 0x262B,
    SMSG_GAME_TIME_SET                                  = 0x26CC,
    SMSG_GAME_TIME_UPDATE                               = 0x26CB,
    SMSG_GAME_EVENT_DEBUG_LOG                           = 0x0000,
    SMSG_GM_PLAYER_INFO                                 = 0x26F8,
    SMSG_GOD_MODE                                       = 0x26BA,
    SMSG_GROUP_ACTION_THROTTLED                         = 0x2524,
    SMSG_HEALTH_UPDATE                                  = 0x267F,
    SMSG_INVALIDATE_PLAYER                              = 0x2654,
    SMSG_INVALID_PROMOTION_CODE                         = 0x2713,
    SMSG_ITEM_ADD_PASSIVE                               = 0x0000,
    SMSG_REMOVE_ITEM_PASSIVE                            = 0x2546,
    SMSG_SEND_ITEM_PASSIVES                             = 0x2547,
    SMSG_MAP_OBJ_EVENTS                                 = 0x255E,
    SMSG_MESSAGE_BOX                                    = 0x24F3,
    SMSG_MISSILE_CANCEL                                 = 0x255F,
    SMSG_NOTIFY_MONEY                                   = 0x2534, ///< 6.2.3 20726
    SMSG_MOVE_SET_COMPOUND_STATE                        = 0x2D5F,
    SMSG_MOVE_UPDATE_COLLISION_HEIGHT                   = 0x2D2B,
    SMSG_ABORT_NEW_WORLD                                = 0x2533,
    SMSG_OPEN_CONTAINER                                 = 0x26E3,
    SMSG_OPEN_LFG_DUNGEON_FINDER                        = 0x29B0,
    SMSG_PAUSE_MIRROR_TIMER                             = 0x26D0,
    SMSG_CHANGE_PLAYER_DIFFICULTY_RESULT                = 0x26B7,
    SMSG_PLAYER_SKINNED                                 = 0x2706,
    SMSG_PLAY_TIME_WARNING                              = 0x26BC,
    SMSG_PROPOSE_LEVEL_GRANT                            = 0x2692,
    SMSG_SUMMON_RAID_MEMBER_VALIDATE_FAILED             = 0x250B,
    SMSG_REALM_SPLIT                                    = 0x0000,
    SMSG_REFER_A_FRIEND_EXPIRED                         = 0x26E1,
    SMSG_REFER_A_FRIEND_FAILURE                         = 0x266E,
    SMSG_REPORT_PVP_PLAYER_AFK_RESULT                   = 0x265B,
    SMSG_SERVER_TIME                                    = 0x262C,
    SMSG_SERVER_INFO_RESPONSE                           = 0x0000,
    SMSG_SERVER_PERF                                    = 0x0000,
    SMSG_SET_DF_FAST_LAUNCH_RESULT                      = 0x29AC,
    SMSG_SHOW_RATINGS                                   = 0x0000,
    SMSG_SOR_START_EXPERIENCE_INCOMPLETE                = 0x2576,
    SMSG_STREAMING_MOVIES                               = 0x2540,
    SMSG_SUMMON_CANCEL                                  = 0x265A,
    SMSG_SUPPRESS_NPC_GREETINGS                         = 0x2554,
    SMSG_TIME_ADJUSTMENT                                = 0x2D1F,
    SMSG_UPDATE_SERVER_PLAYER_POSITION                  = 0x0000,
    SMSG_WAIT_QUEUE_FINISH                              = 0x24EC,
    SMSG_WAIT_QUEUE_UPDATE                              = 0x24EB,
    SMSG_WARGAME_REQUEST_SUCCESSFULLY_SENT_TO_OPPONENT  = 0x253A,
    SMSG_CHEAT_PLAYER_LOOKUP                            = 0x0000,
    SMSG_DBLOOKUP_RESULTS                               = 0x0000,
    SMSG_DEBUG_AISTATE                                  = 0x0000,
    SMSG_DYNAMIC_DROP_ROLL_RESULT                       = 0x0000,
    SMSG_FORCE_ACTION_SHOW_RESPONSE                     = 0x0000,
    SMSG_FORCE_ANIM                                     = 0x2712,
    SMSG_GHOSTEE_GONE                                   = 0x0000,
    SMSG_KICK_REASON                                    = 0x2798,
    SMSG_RESET_RANGED_COMBAT_TIMER                      = 0x2695,
    SMSG_SCRIPT_MESSAGE                                 = 0x0000,
    SMSG_SERVER_BUCK_DATA                               = 0x0000,
    SMSG_SERVER_BUCK_DATA_START                         = 0x0000,
    SMSG_SHOW_MAILBOX                                   = 0x275F,
};

/// Player state
enum SessionStatus
{
    STATUS_AUTHED = 0,                                          // Player authenticated (_player == NULL, m_playerRecentlyLogout = false or will be reset before handler call, m_GUID have garbage)
    STATUS_LOGGEDIN,                                            // Player in game (_player != NULL, m_GUID == _player->GetGUID(), inWorld())
    STATUS_TRANSFER,                                            // Player transferring to another map (_player != NULL, m_GUID == _player->GetGUID(), !inWorld())
    STATUS_LOGGEDIN_OR_RECENTLY_LOGGOUT,                        // _player != NULL or _player == NULL && m_playerRecentlyLogout && m_playerLogout, m_GUID store last _player guid)
    STATUS_NEVER,                                               // Opcode not accepted from client (deprecated or server side only)
    STATUS_UNHANDLED                                            // Opcode not handled yet
};

enum PacketProcessing
{
    PROCESS_INPLACE = 0,                                        // process packet whenever we receive it - mostly for non-handled or non-implemented packets
    PROCESS_THREADUNSAFE,                                       // packet is not thread-safe - process it in World::UpdateSessions()
    PROCESS_THREADSAFE                                          // packet is thread-safe - process it in Map::Update()
};

enum IRPacketProcessing
 {
     PROCESS_LOCAL           = 0,                            // Never send to interrealm
     PROCESS_DISTANT_IF_NEED = 1,                            // Send to interrealm if needed (player is on bg)
 };


class WorldPacket;
class WorldSession;

typedef void(WorldSession::*g_OpcodeHandlerType)(WorldPacket& recvPacket);

struct OpcodeHandler
{
    OpcodeHandler() {}
    OpcodeHandler(char const* _name, SessionStatus _status, PacketProcessing _processing, g_OpcodeHandlerType _handler, IRPacketProcessing _forwardToIR)
        : name(_name), status(_status), packetProcessing(_processing), handler(_handler), forwardToIR(_forwardToIR) {}

    char const* name;
    SessionStatus status;
    PacketProcessing packetProcessing;
    g_OpcodeHandlerType handler;
	IRPacketProcessing forwardToIR;
};

extern OpcodeHandler* g_OpcodeTable[TRANSFER_DIRECTION_MAX][NUM_OPCODE_HANDLERS];
void InitOpcodes();

// Lookup opcode name for human understandable logging
inline std::string GetOpcodeNameForLogging(uint16 id, int p_Direction)
{
    uint32 opcode = uint32(id);
    std::ostringstream ss;
    ss << '[';

    if (id < UNKNOWN_OPCODE)
    {
        OpcodeHandler* handler = g_OpcodeTable[p_Direction][uint32(id) & 0x7FFF];

        if (!handler)
            ss << "UNKNOWN OPCODE";
        else
            ss << handler->name;
    }
    else
        ss << "INVALID OPCODE";

    ss << " 0x" << std::hex << std::uppercase << opcode << std::nouppercase << " (" << std::dec << opcode << ")]";
    return ss.str();
}


inline bool CanBeSentDuringInterRealm(uint16 id)
{
    switch (id)
    {
        case SMSG_CHAT:
        case SMSG_CONTACT_LIST:
        case SMSG_GUILD_BANK_QUERY_RESULTS:
        case SMSG_GUILD_COMMAND_RESULT:
        case SMSG_GUILD_INVITE:
        case SMSG_QUERY_GUILD_INFO_RESPONSE:
        case SMSG_GUILD_ROSTER:
            return true;
    }

    return false;
}

#endif
/// @}
