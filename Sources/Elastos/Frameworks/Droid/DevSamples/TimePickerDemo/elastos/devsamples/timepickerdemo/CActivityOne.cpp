
#include "CActivityOne.h"
#include "R.h"
#include <elastos/utility/logging/Logger.h>

using Elastos::Utility::Logging::Logger;

namespace Elastos {
namespace DevSamples {
namespace TimePickerDemo {

static const String DBG_TAG("CActivityOne");

CAR_OBJECT_IMPL(CActivityOne)

ECode CActivityOne::constructor()
{
    Logger::I(DBG_TAG, " >> constructor()");
    return Activity::constructor();
}

ECode CActivityOne::OnCreate(
    /* [in] */ IBundle* savedInstanceState)
{
    Activity::OnCreate(savedInstanceState);
    Logger::I(DBG_TAG, " >> OnCreate");
    SetContentView(R::layout::main);

    AutoPtr<IView> view = FindViewById(R::id::timePicker);
    mTimePicker = ITimePicker::Probe(view);

    // mTimePicker->SetIs24HourView(TRUE);
    mTimePicker->SetCurrentHour(19);
    mTimePicker->SetCurrentMinute(50);

    return NOERROR;
}

ECode CActivityOne::OnStart()
{
    Logger::I(DBG_TAG, " >> OnStart()");
    return Activity::OnStart();
}

ECode CActivityOne::OnResume()
{
    Logger::I(DBG_TAG, " >> OnResume()");
    return Activity::OnResume();
}

ECode CActivityOne::OnPause()
{
    Logger::I(DBG_TAG, " >> OnPause()");
    return Activity::OnPause();
}

ECode CActivityOne::OnStop()
{
    Logger::I(DBG_TAG, " >> OnStop()");
    return Activity::OnStop();
}

ECode CActivityOne::OnDestroy()
{
    Logger::I(DBG_TAG, " >> OnDestroy()");
    return Activity::OnDestroy();
}

} // namespace TimePickerDemo
} // namespace DevSamples
} // namespace Elastos