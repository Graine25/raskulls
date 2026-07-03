#include <rex/cvar.h>
#include <rex/hook.h>
#include <rex/types.h>
#include <rex/system/kernel_state.h>
#include <chrono>
#include <cstdint>
#include <cmath>
#include <cstring>
#include <rex/ui/imgui_dialog.h>
#include "rex_macros.h"

REXCVAR_DEFINE_STRING(ras_data_root, "", "Raskulls/config",
                      "Path to game asset directory. Overrides the default data root when non-empty.");

REX_STUB(__imp__XUsbcamCreate)
REX_STUB(__imp__XUsbcamDestroy)
REX_STUB(__imp__XUsbcamGetState)
REX_STUB(__imp__XUsbcamSetConfig)
REX_STUB(__imp__XUsbcamSetView)
REX_STUB(__imp__XUsbcamSetCaptureMode)
REX_STUB(__imp__XUsbcamReadFrame)
