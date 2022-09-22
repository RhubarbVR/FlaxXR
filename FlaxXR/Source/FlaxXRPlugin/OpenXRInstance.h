#pragma once
#include "Engine/Core/Config/GameSettings.h";
#include "Engine/Graphics/GPUDevice.h"

#ifdef OPENXR_SUPPORT

#if GRAPHICS_API_VULKAN
#define XR_USE_GRAPHICS_API_VULKAN
#include <vulkan/vulkan.h>
#endif // GRAPHICS_API_VULKAN

#ifdef GRAPHICS_API_DIRECTX12
#define XR_USE_GRAPHICS_API_D3D12
#include <d3d12.h>
#endif // GRAPHICS_API_DIRECTX12

#ifdef GRAPHICS_API_DIRECTX11
#define XR_USE_GRAPHICS_API_D3D11
#include <d3d11.h>
#endif // GRAPHICS_API_DIRECTX11

#ifdef PLATFORM_ARCH_X64 

#endif

#include <openxr/openxr.h>
#include <openxr/openxr_platform.h>
#include <openxr/openxr_platform_defines.h>
#include <openxr/openxr_reflection.h>
#endif // OPENXR_SUPPORT


class OpenXRInstance
{
#ifdef OPENXR_SUPPORT
	// Changing to HANDHELD_DISPLAY or a future form factor may work, but has not been tested.
	XrFormFactor form_factor = XR_FORM_FACTOR_HEAD_MOUNTED_DISPLAY;

	// Changing the form_factor may require changing the view_type too.
	XrViewConfigurationType view_type = XR_VIEW_CONFIGURATION_TYPE_PRIMARY_STEREO;

	// Typically STAGE for room scale/standing, LOCAL for seated
	XrReferenceSpaceType play_space_type = XR_REFERENCE_SPACE_TYPE_LOCAL;
	XrSpace play_space = XR_NULL_HANDLE;

	// the instance handle can be thought of as the basic connection to the OpenXR runtime
	XrInstance instance = XR_NULL_HANDLE;
	// the system represents an (opaque) set of XR devices in use, managed by the runtime
	XrSystemId system_id = XR_NULL_SYSTEM_ID;
	// the session deals with the renderloop submitting frames to the runtime
	XrSession session = XR_NULL_HANDLE;
	void UpdateResultMSG(XrResult result);

#endif
public:
	String msg;
    
	
	bool Init();
};

