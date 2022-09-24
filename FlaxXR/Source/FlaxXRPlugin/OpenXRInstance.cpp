#include "OpenXRInstance.h"
#include <Engine/Engine/Globals.h>
#include <Engine/Debug/DebugLog.h>

#if ((GRAPHICS_API_VULKAN | GRAPHICS_API_DIRECTX12 | GRAPHICS_API_DIRECTX11) & OPENXR_SUPPORT)
void OpenXRInstance::UpdateResultMSG(XrResult result) {
	if (XR_SUCCEEDED(result)) {
		msg = "";
		return;
	}
	msg = "Error: ";
	if (result == XR_TIMEOUT_EXPIRED) {
		msg += "XR_TIMEOUT_EXPIRED";
	}
	else if (result == XR_SESSION_LOSS_PENDING) {
		msg += "XR_SESSION_LOSS_PENDING";
	}
	else if (result == XR_EVENT_UNAVAILABLE) {
		msg += "XR_EVENT_UNAVAILABLE";
	}
	else if (result == XR_SPACE_BOUNDS_UNAVAILABLE) {
		msg += "XR_SPACE_BOUNDS_UNAVAILABLE";
	}
	else if (result == XR_SESSION_NOT_FOCUSED) {
		msg += "XR_SESSION_NOT_FOCUSED";
	}
	else if (result == XR_FRAME_DISCARDED) {
		msg += "XR_FRAME_DISCARDED";
	}
	else if (result == XR_ERROR_VALIDATION_FAILURE) {
		msg += "XR_ERROR_VALIDATION_FAILURE";
	}
	else if (result == XR_ERROR_RUNTIME_FAILURE) {
		msg += "XR_ERROR_RUNTIME_FAILURE";
	}
	else if (result == XR_ERROR_OUT_OF_MEMORY) {
		msg += "XR_ERROR_OUT_OF_MEMORY";
	}
	else if (result == XR_ERROR_API_VERSION_UNSUPPORTED) {
		msg += "XR_ERROR_API_VERSION_UNSUPPORTED";
	}
	else if (result == XR_ERROR_INITIALIZATION_FAILED) {
		msg += "XR_ERROR_INITIALIZATION_FAILED";
	}
	else if (result == XR_ERROR_FUNCTION_UNSUPPORTED) {
		msg += "XR_ERROR_FUNCTION_UNSUPPORTED";
	}
	else if (result == XR_ERROR_FEATURE_UNSUPPORTED) {
		msg += "XR_ERROR_FEATURE_UNSUPPORTED";
	}
	else if (result == XR_ERROR_EXTENSION_NOT_PRESENT) {
		msg += "XR_ERROR_EXTENSION_NOT_PRESENT";
	}
	else if (result == XR_ERROR_LIMIT_REACHED) {
		msg += "XR_ERROR_LIMIT_REACHED";
	}
	else if (result == XR_ERROR_SIZE_INSUFFICIENT) {
		msg += "XR_ERROR_SIZE_INSUFFICIENT";
	}
	else if (result == XR_ERROR_HANDLE_INVALID) {
		msg += "XR_ERROR_HANDLE_INVALID";
	}
	else if (result == XR_ERROR_INSTANCE_LOST) {
		msg += "XR_ERROR_INSTANCE_LOST";
	}
	else if (result == XR_ERROR_SESSION_RUNNING) {
		msg += "XR_ERROR_SESSION_RUNNING";
	}
	else if (result == XR_ERROR_SESSION_NOT_RUNNING) {
		msg += "XR_ERROR_SESSION_NOT_RUNNING";
	}
	else if (result == XR_ERROR_SESSION_LOST) {
		msg += "XR_ERROR_SESSION_LOST";
	}
	else if (result == XR_ERROR_SYSTEM_INVALID) {
		msg += "XR_ERROR_SYSTEM_INVALID";
	}
	else if (result == XR_ERROR_PATH_INVALID) {
		msg += "XR_ERROR_PATH_INVALID";
	}
	else if (result == XR_ERROR_PATH_COUNT_EXCEEDED) {
		msg += "XR_ERROR_PATH_COUNT_EXCEEDED";
	}
	else if (result == XR_ERROR_PATH_FORMAT_INVALID) {
		msg += "XR_ERROR_PATH_FORMAT_INVALID";
	}
	else if (result == XR_ERROR_PATH_UNSUPPORTED) {
		msg += "XR_ERROR_PATH_UNSUPPORTED";
	}
	else if (result == XR_ERROR_LAYER_INVALID) {
		msg += "XR_ERROR_LAYER_INVALID";
	}
	else if (result == XR_ERROR_LAYER_LIMIT_EXCEEDED) {
		msg += "XR_ERROR_LAYER_LIMIT_EXCEEDED";
	}
	else if (result == XR_ERROR_SWAPCHAIN_RECT_INVALID) {
		msg += "XR_ERROR_SWAPCHAIN_RECT_INVALID";
	}
	else if (result == XR_ERROR_SWAPCHAIN_FORMAT_UNSUPPORTED) {
		msg += "XR_ERROR_SWAPCHAIN_FORMAT_UNSUPPORTED";
	}
	else if (result == XR_ERROR_ACTION_TYPE_MISMATCH) {
		msg += "XR_ERROR_ACTION_TYPE_MISMATCH";
	}
	else if (result == XR_ERROR_SESSION_NOT_READY) {
		msg += "XR_ERROR_SESSION_NOT_READY";
	}
	else if (result == XR_ERROR_SESSION_NOT_STOPPING) {
		msg += "XR_ERROR_SESSION_NOT_STOPPING";
	}
	else if (result == XR_ERROR_TIME_INVALID) {
		msg += "XR_ERROR_TIME_INVALID";
	}
	else if (result == XR_ERROR_REFERENCE_SPACE_UNSUPPORTED) {
		msg += "XR_ERROR_REFERENCE_SPACE_UNSUPPORTED";
	}
	else if (result == XR_ERROR_FILE_ACCESS_ERROR) {
		msg += "XR_ERROR_FILE_ACCESS_ERROR";
	}
	else if (result == XR_ERROR_FILE_CONTENTS_INVALID) {
		msg += "XR_ERROR_FILE_CONTENTS_INVALID";
	}
	else if (result == XR_ERROR_FORM_FACTOR_UNSUPPORTED) {
		msg += "XR_ERROR_FORM_FACTOR_UNSUPPORTED";
	}
	else if (result == XR_ERROR_FORM_FACTOR_UNAVAILABLE) {
		msg += "XR_ERROR_FORM_FACTOR_UNAVAILABLE";
	}
	else if (result == XR_ERROR_API_LAYER_NOT_PRESENT) {
		msg += "XR_ERROR_API_LAYER_NOT_PRESENT";
	}
	else if (result == XR_ERROR_CALL_ORDER_INVALID) {
		msg += "XR_ERROR_CALL_ORDER_INVALID";
	}
	else if (result == XR_ERROR_GRAPHICS_DEVICE_INVALID) {
		msg += "XR_ERROR_GRAPHICS_DEVICE_INVALID";
	}
	else if (result == XR_ERROR_POSE_INVALID) {
		msg += "XR_ERROR_POSE_INVALID";
	}
	else if (result == XR_ERROR_INDEX_OUT_OF_RANGE) {
		msg += "XR_ERROR_INDEX_OUT_OF_RANGE";
	}
	else if (result == XR_ERROR_VIEW_CONFIGURATION_TYPE_UNSUPPORTED) {
		msg += "XR_ERROR_VIEW_CONFIGURATION_TYPE_UNSUPPORTED";
	}
	else if (result == XR_ERROR_ENVIRONMENT_BLEND_MODE_UNSUPPORTED) {
		msg += "XR_ERROR_ENVIRONMENT_BLEND_MODE_UNSUPPORTED";
	}
	else if (result == XR_ERROR_NAME_DUPLICATED) {
		msg += "XR_ERROR_NAME_DUPLICATED";
	}
	else if (result == XR_ERROR_NAME_INVALID) {
		msg += "XR_ERROR_NAME_INVALID";
	}
	else if (result == XR_ERROR_ACTIONSET_NOT_ATTACHED) {
		msg += "XR_ERROR_ACTIONSET_NOT_ATTACHED";
	}
	else if (result == XR_ERROR_ACTIONSETS_ALREADY_ATTACHED) {
		msg += "XR_ERROR_ACTIONSETS_ALREADY_ATTACHED";
	}
	else if (result == XR_ERROR_LOCALIZED_NAME_DUPLICATED) {
		msg += "XR_ERROR_LOCALIZED_NAME_DUPLICATED";
	}
	else if (result == XR_ERROR_LOCALIZED_NAME_INVALID) {
		msg += "XR_ERROR_LOCALIZED_NAME_INVALID";
	}
	else if (result == XR_ERROR_GRAPHICS_REQUIREMENTS_CALL_MISSING) {
		msg += "XR_ERROR_GRAPHICS_REQUIREMENTS_CALL_MISSING";
	}
	else if (result == XR_ERROR_RUNTIME_UNAVAILABLE) {
		msg += "XR_ERROR_RUNTIME_UNAVAILABLE";
	}
	else if (result == XR_ERROR_ANDROID_THREAD_SETTINGS_ID_INVALID_KHR) {
		msg += "XR_ERROR_ANDROID_THREAD_SETTINGS_ID_INVALID_KHR";
	}
	else if (result == XR_ERROR_ANDROID_THREAD_SETTINGS_FAILURE_KHR) {
		msg += "XR_ERROR_ANDROID_THREAD_SETTINGS_FAILURE_KHR";
	}
	else if (result == XR_ERROR_CREATE_SPATIAL_ANCHOR_FAILED_MSFT) {
		msg += "XR_ERROR_CREATE_SPATIAL_ANCHOR_FAILED_MSFT";
	}
	else if (result == XR_ERROR_SECONDARY_VIEW_CONFIGURATION_TYPE_NOT_ENABLED_MSFT) {
		msg += "XR_ERROR_SECONDARY_VIEW_CONFIGURATION_TYPE_NOT_ENABLED_MSFT";
	}
	else if (result == XR_ERROR_CONTROLLER_MODEL_KEY_INVALID_MSFT) {
		msg += "XR_ERROR_CONTROLLER_MODEL_KEY_INVALID_MSFT";
	}
	else if (result == XR_ERROR_REPROJECTION_MODE_UNSUPPORTED_MSFT) {
		msg += "XR_ERROR_REPROJECTION_MODE_UNSUPPORTED_MSFT";
	}
	else if (result == XR_ERROR_COMPUTE_NEW_SCENE_NOT_COMPLETED_MSFT) {
		msg += "XR_ERROR_COMPUTE_NEW_SCENE_NOT_COMPLETED_MSFT";
	}
	else if (result == XR_ERROR_SCENE_COMPONENT_ID_INVALID_MSFT) {
		msg += "XR_ERROR_SCENE_COMPONENT_ID_INVALID_MSFT";
	}
	else if (result == XR_ERROR_SCENE_COMPONENT_TYPE_MISMATCH_MSFT) {
		msg += "XR_ERROR_SCENE_COMPONENT_TYPE_MISMATCH_MSFT";
	}
	else if (result == XR_ERROR_SCENE_MESH_BUFFER_ID_INVALID_MSFT) {
		msg += "XR_ERROR_SCENE_MESH_BUFFER_ID_INVALID_MSFT";
	}
	else if (result == XR_ERROR_SCENE_COMPUTE_FEATURE_INCOMPATIBLE_MSFT) {
		msg += "XR_ERROR_SCENE_COMPUTE_FEATURE_INCOMPATIBLE_MSFT";
	}
	else if (result == XR_ERROR_SCENE_COMPUTE_CONSISTENCY_MISMATCH_MSFT) {
		msg += "XR_ERROR_SCENE_COMPUTE_CONSISTENCY_MISMATCH_MSFT";
	}
	else if (result == XR_ERROR_DISPLAY_REFRESH_RATE_UNSUPPORTED_FB) {
		msg += "XR_ERROR_DISPLAY_REFRESH_RATE_UNSUPPORTED_FB";
	}
	else if (result == XR_ERROR_COLOR_SPACE_UNSUPPORTED_FB) {
		msg += "XR_ERROR_COLOR_SPACE_UNSUPPORTED_FB";
	}
	else if (result == XR_ERROR_SPACE_COMPONENT_NOT_SUPPORTED_FB) {
		msg += "XR_ERROR_SPACE_COMPONENT_NOT_SUPPORTED_FB";
	}
	else if (result == XR_ERROR_SPACE_COMPONENT_NOT_ENABLED_FB) {
		msg += "XR_ERROR_SPACE_COMPONENT_NOT_ENABLED_FB";
	}
	else if (result == XR_ERROR_SPACE_COMPONENT_STATUS_PENDING_FB) {
		msg += "XR_ERROR_SPACE_COMPONENT_STATUS_PENDING_FB";
	}
	else if (result == XR_ERROR_SPACE_COMPONENT_STATUS_ALREADY_SET_FB) {
		msg += "XR_ERROR_SPACE_COMPONENT_STATUS_ALREADY_SET_FB";
	}
	else if (result == XR_ERROR_UNEXPECTED_STATE_PASSTHROUGH_FB) {
		msg += "XR_ERROR_UNEXPECTED_STATE_PASSTHROUGH_FB";
	}
	else if (result == XR_ERROR_FEATURE_ALREADY_CREATED_PASSTHROUGH_FB) {
		msg += "XR_ERROR_FEATURE_ALREADY_CREATED_PASSTHROUGH_FB";
	}
	else if (result == XR_ERROR_FEATURE_REQUIRED_PASSTHROUGH_FB) {
		msg += "XR_ERROR_FEATURE_REQUIRED_PASSTHROUGH_FB";
	}
	else if (result == XR_ERROR_NOT_PERMITTED_PASSTHROUGH_FB) {
		msg += "XR_ERROR_NOT_PERMITTED_PASSTHROUGH_FB";
	}
	else if (result == XR_ERROR_INSUFFICIENT_RESOURCES_PASSTHROUGH_FB) {
		msg += "XR_ERROR_INSUFFICIENT_RESOURCES_PASSTHROUGH_FB";
	}
	else if (result == XR_ERROR_UNKNOWN_PASSTHROUGH_FB) {
		msg += "XR_ERROR_UNKNOWN_PASSTHROUGH_FB";
	}
	else if (result == XR_ERROR_RENDER_MODEL_KEY_INVALID_FB) {
		msg += "XR_ERROR_RENDER_MODEL_KEY_INVALID_FB";
	}
	else if (result == XR_RENDER_MODEL_UNAVAILABLE_FB) {
		msg += "XR_RENDER_MODEL_UNAVAILABLE_FB";
	}
	else if (result == XR_ERROR_MARKER_NOT_TRACKED_VARJO) {
		msg += "XR_ERROR_MARKER_NOT_TRACKED_VARJO";
	}
	else if (result == XR_ERROR_MARKER_ID_INVALID_VARJO) {
		msg += "XR_ERROR_MARKER_ID_INVALID_VARJO";
	}
	else if (result == XR_ERROR_SPATIAL_ANCHOR_NAME_NOT_FOUND_MSFT) {
		msg += "XR_ERROR_SPATIAL_ANCHOR_NAME_NOT_FOUND_MSFT";
	}
	else if (result == XR_ERROR_SPATIAL_ANCHOR_NAME_INVALID_MSFT) {
		msg += "XR_ERROR_SPATIAL_ANCHOR_NAME_INVALID_MSFT";
	}
	else if (result == XR_RESULT_MAX_ENUM) {
		msg += "XR_RESULT_MAX_ENUM";
	}
	else if (result == XR_TIMEOUT_EXPIRED) {
		msg += "XR_RESULT_MAX_ENUM";
	}

	else
	{
		char resultString[XR_MAX_RESULT_STRING_SIZE];
		xrResultToString(instance, result, resultString);
		msg += resultString;
	}
}
#endif // ((GRAPHICS_API_VULKAN | GRAPHICS_API_DIRECTX12 | GRAPHICS_API_DIRECTX11) & OPENXR_SUPPORT)



bool OpenXRInstance::Init() {
#if ((GRAPHICS_API_VULKAN | GRAPHICS_API_DIRECTX12 | GRAPHICS_API_DIRECTX11) & OPENXR_SUPPORT)
	// --- Create XrInstance
#if (GRAPHICS_API_VULKAN & GRAPHICS_API_DIRECTX12 & GRAPHICS_API_DIRECTX11)
	const int enabled_ext_count = 3;
#elif (GRAPHICS_API_DIRECTX12 & GRAPHICS_API_DIRECTX11)
	const int enabled_ext_count = 2;
#elif (GRAPHICS_API_VULKAN & GRAPHICS_API_DIRECTX11)
	const int enabled_ext_count = 2;
#elif (GRAPHICS_API_VULKAN & GRAPHICS_API_DIRECTX12)
	const int enabled_ext_count = 2;
#elif (GRAPHICS_API_DIRECTX12)
	const int enabled_ext_count = 1;
#elif (GRAPHICS_API_DIRECTX11)
	const int enabled_ext_count = 1;
#elif (GRAPHICS_API_VULKAN)
	const int enabled_ext_count = 1;
#endif
	const char* enabled_exts[enabled_ext_count] =
	{
#ifdef XR_USE_GRAPHICS_API_VULKAN
		XR_KHR_VULKAN_ENABLE_EXTENSION_NAME,
#endif
#ifdef XR_USE_GRAPHICS_API_D3D11
		XR_KHR_D3D11_ENABLE_EXTENSION_NAME,
#endif
#ifdef XR_USE_GRAPHICS_API_D3D12
		XR_KHR_D3D12_ENABLE_EXTENSION_NAME,
#endif
	};
	// same can be done for API layers, but API layers can also be enabled by env var
	msg = "Starting OpenXR";



	// xrEnumerate*() functions are usually called once with CapacityInput = 0.
	// The function will write the required amount into CountOutput. We then have
	// to allocate an array to hold CountOutput elements and call the function
	// with CountOutput as CapacityInput.
	uint32_t ext_count = 0;
	auto result = xrEnumerateInstanceExtensionProperties(NULL, 0, &ext_count, NULL);

	/* TODO: instance null will not be able to convert XrResult to string */
	if (!XR_SUCCEEDED(result)) {
		UpdateResultMSG(result);
		msg += " Failed to enumerate number of extension properties";
		return false;
	}


	XrExtensionProperties* ext_props = (XrExtensionProperties*)malloc(sizeof(XrExtensionProperties) * ext_count);
	for (uint16_t i = 0; i < ext_count; i++) {
		// we usually have to fill in the type (for validation) and set
		// next to NULL (or a pointer to an extension specific struct)
		ext_props[i].type = XR_TYPE_EXTENSION_PROPERTIES;
		ext_props[i].next = NULL;
	}

	result = xrEnumerateInstanceExtensionProperties(NULL, ext_count, &ext_count, ext_props);
	if (!XR_SUCCEEDED(result)) {
		UpdateResultMSG(result);
		msg += " Failed to enumerate extension properties";
		return false;
	}


	bool depth_supported = false;

	bool dx11_supported = false;
	bool dx12_supported = false;
	bool vulkan_supported = false;

	for (uint32_t i = 0; i < ext_count; i++) {
#ifdef XR_USE_GRAPHICS_API_D3D11
		if (strcmp(XR_KHR_D3D11_ENABLE_EXTENSION_NAME, ext_props[i].extensionName) == 0) {
			dx11_supported = true;
		}
#endif
#ifdef XR_USE_GRAPHICS_API_D3D12
		if (strcmp(XR_KHR_D3D12_ENABLE_EXTENSION_NAME, ext_props[i].extensionName) == 0) {
			dx12_supported = true;
		}
#endif
#ifdef XR_USE_GRAPHICS_API_VULKAN
		if (strcmp(XR_KHR_VULKAN_ENABLE_EXTENSION_NAME, ext_props[i].extensionName) == 0) {
			dx12_supported = true;
		}
#endif
		if (strcmp(XR_KHR_COMPOSITION_LAYER_DEPTH_EXTENSION_NAME, ext_props[i].extensionName) == 0) {
			depth_supported = true;
		}
	}
	free(ext_props);

	if (!(dx11_supported || dx12_supported || vulkan_supported)) {
		msg = "Runtime does not support extensions!";
		return false;
	}






	XrInstanceCreateInfo instance_create_info = { XR_TYPE_INSTANCE_CREATE_INFO };
	instance_create_info.enabledExtensionCount = enabled_ext_count;
	instance_create_info.enabledExtensionNames =   enabled_exts;
	auto settings = GameSettings::Get();
	snprintf(instance_create_info.applicationInfo.applicationName, sizeof(instance_create_info.applicationInfo.applicationName), "%ls", settings->ProductName.GetText());
	snprintf(instance_create_info.applicationInfo.engineName, sizeof(instance_create_info.applicationInfo.engineName), "Flax Engine");
	instance_create_info.applicationInfo.apiVersion = XR_CURRENT_API_VERSION;
	instance_create_info.applicationInfo.engineVersion = Globals::EngineBuildNumber;
	instance_create_info.applicationInfo.applicationVersion = 1;
#ifdef XR_USE_PLATFORM_ANDROID
	XrInstanceCreateInfoAndroidKHR create_android = { XR_TYPE_INSTANCE_CREATE_INFO_ANDROID_KHR };
	create_android.applicationVM = android_vm;//need to setup for flax
	create_android.applicationActivity = android_activity;//need to setup for flax
	instance_create_info.next = (void*)&create_android;
#endif
	result = xrCreateInstance(&instance_create_info, &instance);
	if (!XR_SUCCEEDED(result)) {
		UpdateResultMSG(result);
		msg += " Failed to create XR instance";
		return false;
	}

	
	XrSystemGetInfo system_get_info = { XR_TYPE_SYSTEM_GET_INFO };
	system_get_info.formFactor = form_factor;
	system_get_info.next = NULL;

	result = xrGetSystem(instance, &system_get_info, &system_id);
	if (!XR_SUCCEEDED(result)) {
		UpdateResultMSG(result);
		msg += " Failed to Get XR System";
		return false;
	}
	XrSystemProperties system_props = { XR_TYPE_SYSTEM_PROPERTIES };
	system_props.next = NULL;

	result = xrGetSystemProperties(instance, system_id, &system_props);
	if (!XR_SUCCEEDED(result)) {
		UpdateResultMSG(result);
		msg += " Failed to Get XR System Properties";
		return false;
	}

	result = xrEnumerateViewConfigurationViews(instance, system_id, view_type, 0, &view_count, NULL);
	if (!XR_SUCCEEDED(result)) {
		UpdateResultMSG(result);
		msg += " Failed to get view configuration view count!";
		return false;
	}

	viewconfig_views = (XrViewConfigurationView*)malloc(sizeof(XrViewConfigurationView) * view_count);
	for (uint32_t i = 0; i < view_count; i++) {
		viewconfig_views[i].type = XR_TYPE_VIEW_CONFIGURATION_VIEW;
		viewconfig_views[i].next = NULL;
	}

	result = xrEnumerateViewConfigurationViews(instance, system_id, view_type, view_count,
		&view_count, viewconfig_views);
	if (!XR_SUCCEEDED(result)) {
		UpdateResultMSG(result);
		msg += " Failed to enumerate view configuration views!";
		return false;
	}

#ifdef XR_USE_GRAPHICS_API_D3D11
	XrGraphicsRequirementsD3D11KHR dx11_reqs = { XR_TYPE_GRAPHICS_REQUIREMENTS_D3D11_KHR };
	result = xrGetD3D11GraphicsRequirementsKHR(instance, system_id, &dx11_reqs);
	if (!XR_SUCCEEDED(result)) {
		UpdateResultMSG(result);
		msg += " Failed to Get XrGraphicsRequirementsD3D11!";
		return false;
	}
#endif
#ifdef XR_USE_GRAPHICS_API_D3D12
	XrGraphicsRequirementsD3D12KHR dx12_reqs = { XR_TYPE_GRAPHICS_REQUIREMENTS_D3D12_KHR };
	result = xrGetD3D12GraphicsRequirementsKHR(instance, system_id, &dx12_reqs);
	if (!XR_SUCCEEDED(result)) {
		UpdateResultMSG(result);
		msg += " Failed to Get XrGraphicsRequirementsD3D12!";
		return false;
	}
#endif
#ifdef XR_USE_GRAPHICS_API_VULKAN
	XrGraphicsRequirementsVulkanKHR vk_reqs = { XR_TYPE_GRAPHICS_REQUIREMENTS_VULKAN_KHR };
	result = xrGetVulkanGraphicsRequirementsKHR(instance, system_id, &vk_reqs);
	if (!XR_SUCCEEDED(result)) {
		UpdateResultMSG(result);
		msg += " Failed to Get XrGraphicsRequirementsVulkan!";
		return false;
	}
#endif


	msg = "Started OpenXR";
	return true;
#else // OPENXR_SUPPORT
	return false;
#endif // OPENXR_SUPPORT
}