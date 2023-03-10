#ifndef _SIPUMT_
#define _SIPUMT_
#include <kamek.hpp>
#include <game/visual/effect/EffectMgr.hpp>
#include <game/System/Archive.hpp>
#include <game/Race/RaceData.hpp>
#include <game/Race/Kart/KartHolder.hpp>
#include <game/Sound/Actors/KartSound.hpp>
#include <SkillIssuePack.hpp>

/*Implements UMTs. This is a fully custom version so it has its own rules:
-It takes 550 frames to charge (300 for a SMT)
-It lasts 1.33x as long as a SMT
-It multiplies the kart speed by 1.27 (1.2 for SMTs)
-As long as it is active, all boosts received by the karts will extend that multiplier boost, allowing snaking that preserves the higher multiplier
-In effect though, that last perk is mostly only useful for charging a MT/SMT on a boost panel that was hit after releasing a UMT
*/

#define UMTEFFECTSCOUNT 8
enum UMTeffects{ //Chips are not implemented currently due to pure laziness
    rk_driftSpark3L_Spark00,
    rk_driftSpark3L_Spark01,
    rk_driftSpark3R_Spark00,
    rk_driftSpark3R_Spark01,
    rk_purpleBoost,
    rk_purpleBoost_2,
    rk_purpleBoost_3,
    rk_purpleBoost_4
    //rk_driftSpark2L_Chip00,
    //rk_driftSpark2R_Chip00,
    //rk_driftSpark3L1T_Chip00 ,
    //rk_driftSpark3L1T_Spark00,
    //rk_driftSpark3L1T_Spark01,
    //rk_driftSpark3R1T_Chip00,
    //rk_driftSpark3R1T_Spark00,
    //rk_driftSpark3R1T_Spark01,
};

class ExpandedPlayerEffects : public PlayerEffects {
public:
    explicit ExpandedPlayerEffects(Kart *kart) : PlayerEffects(kart) { };
    ~ExpandedPlayerEffects() override {
        EGG::Effect **array = rk_purpleMT;
        if(isBike == false){
            for(int i = 0; i < UMTEFFECTSCOUNT; i++) delete(array[i]);
            delete[] array;   
        }
    }
    EGG::Effect **rk_purpleMT;
    static const char *UMTNames[8];
};
#endif