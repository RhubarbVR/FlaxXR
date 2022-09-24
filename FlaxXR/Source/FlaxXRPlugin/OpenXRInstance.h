#pragma once
#include "Engine/Core/Config/GameSettings.h";
#include "Engine/Graphics/GPUDevice.h"

#ifdef OPENXR_SUPPORT

#if GRAPHICS_API_VULKAN
#define XR_USE_GRAPHICS_API_VULKAN
#define VK_NO_PROTOTYPES
#include "Engine\GraphicsDevice\Vulkan\GPUDeviceVulkan.h"
#include "Engine\GraphicsDevice\Vulkan\GPUAdapterVulkan.h"
#include "Engine\GraphicsDevice\Vulkan\QueueVulkan.h"
#include <vulkan/vulkan.h>
#endif // GRAPHICS_API_VULKAN

#ifdef GRAPHICS_API_DIRECTX12
#define XR_USE_GRAPHICS_API_D3D12
#include "Engine\GraphicsDevice\DirectX\DX12\GPUDeviceDX12.h"

#include <d3d12.h>
#endif // GRAPHICS_API_DIRECTX12

#ifdef GRAPHICS_API_DIRECTX11
#define XR_USE_GRAPHICS_API_D3D11
#include "Engine\GraphicsDevice\DirectX\DX11\GPUDeviceDX11.h"

#include <d3d11.h>

#endif // GRAPHICS_API_DIRECTX11

//#ifdef PLATFORM_ANDROID
//#define XR_USE_PLATFORM_ANDROID
//
//#include <android/configuration.h>
//#include <android/looper.h>
//#include <android/native_activity.h>
//
//
//#endif

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
	// each physical Display/Eye is described by a view.
	// view_count usually depends on the form_factor / view_type.
	// dynamically allocating all view related structs instead of assuming 2
	// hopefully allows this app to scale easily to different view_counts.
	uint32_t view_count = 0;
	// the viewconfiguration views contain information like resolution about each view
	XrViewConfigurationView* viewconfig_views = NULL;

	// array of view_count containers for submitting swapchains with rendered VR frames
	XrCompositionLayerProjectionView* projection_views = NULL;
	// array of view_count views, filled by the runtime with current HMD display pose
	XrView* views = NULL;

#ifdef XR_USE_GRAPHICS_API_D3D11
	XrGraphicsBindingD3D11KHR graphics_binding_dx11;
#endif
#ifdef XR_USE_GRAPHICS_API_D3D12
	XrGraphicsBindingD3D12KHR graphics_binding_dx12;
#endif
#ifdef XR_USE_GRAPHICS_API_VULKAN
	XrGraphicsBindingVulkanKHR graphics_binding_vk;
#endif

	void UpdateResultMSG(XrResult result);

#endif
public:
	String msg;
    
	
	bool Init();
};

