
#include "FlaxOpenXR.h"
#include "Engine/Core/Log.h"

bool FlaxOpenXR::IsOpenXRSupported()
{
#if ((GRAPHICS_API_VULKAN | GRAPHICS_API_DIRECTX12 | GRAPHICS_API_DIRECTX11) & OPENXR_SUPPORT)
	return true;
#else // OPENXR_SUPPORT
	return false;
#endif // OPENXR_SUPPORT
}

bool FlaxOpenXR::InitOpenXRInstance(void* target) {
#if ((GRAPHICS_API_VULKAN | GRAPHICS_API_DIRECTX12 | GRAPHICS_API_DIRECTX11) & OPENXR_SUPPORT)
	if (target == nullptr) {
		return false;
	}
	return ((OpenXRInstance*)target)->Init();
#else // OPENXR_SUPPORT
	return false;
#endif // OPENXR_SUPPORT
}

String FlaxOpenXR::OpenXRInstanceMSG(void* target) {
#if ((GRAPHICS_API_VULKAN | GRAPHICS_API_DIRECTX12 | GRAPHICS_API_DIRECTX11) & OPENXR_SUPPORT)
	if (target == nullptr) {
		return false;
	}
	return ((OpenXRInstance*)target)->msg;
#else // OPENXR_SUPPORT
	return false;
#endif // OPENXR_SUPPORT
}

void* FlaxOpenXR::BuildOpenXRInstance() {
#if ((GRAPHICS_API_VULKAN | GRAPHICS_API_DIRECTX12 | GRAPHICS_API_DIRECTX11) & OPENXR_SUPPORT)
	return new OpenXRInstance();
#else // OPENXR_SUPPORT
	return nullptr;
#endif // OPENXR_SUPPORT
}

