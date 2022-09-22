// This code was auto-generated. Do not modify it.

#include "Engine/Scripting/BinaryModule.h"
#include "FlaxXRPlugin.Gen.h"

StaticallyLinkedBinaryModuleInitializer StaticallyLinkedBinaryModuleFlaxXRPlugin(GetBinaryModuleFlaxXRPlugin);

extern "C" BinaryModule* GetBinaryModuleFlaxXRPlugin()
{
    static NativeBinaryModule module("FlaxXRPlugin", MAssemblyOptions());
    return &module;
}
