#include <UI/CtrlRaceBase/SIPCtrlRaceBase.hpp>

namespace SIPUI{
CustomCtrlBuilder *CustomCtrlBuilder::sHooks = NULL;
void CustomCtrlBuilder::BuildCustomRaceCtrls(Pages::RaceHUD *racePage, u32 controlCount)
{
   u32 customctrlCount = CustomCtrlBuilder::Count();
   racePage->InitControlGroup(controlCount + customctrlCount);
   CustomCtrlBuilder::CreateCustomCtrls(racePage, controlCount);
   return;
}
kmCall(0x808562d0, CustomCtrlBuilder::BuildCustomRaceCtrls);
}//namespace SIPUI