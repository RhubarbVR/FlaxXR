
#pragma once

#include "Engine/Scripting/Script.h"
#include "Engine/Core/Math/Vector4.h"
#include "OpenXRInstance.h"

/// <summary>
/// FlaxOpenXR Function Library
/// </summary>
API_CLASS(Static) class FLAXXRPLUGIN_API FlaxOpenXR 
{
    DECLARE_SCRIPTING_TYPE_MINIMAL(FlaxOpenXR);

public:

    /// <summary>
    /// Checks If OpenXR is Supported On This Platform
    /// </summary>
    API_FUNCTION() static bool IsOpenXRSupported();

    /// <summary>
    /// Sets up OpenXR instances if Supported On This Platform
    /// </summary>
    API_FUNCTION() static void* BuildOpenXRInstance();

    /// <summary>
    /// Starts OpenXR Instance
    /// </summary>
    API_FUNCTION() static bool InitOpenXRInstance(void* target);
    API_FUNCTION() static String OpenXRInstanceMSG(void* target);

};
