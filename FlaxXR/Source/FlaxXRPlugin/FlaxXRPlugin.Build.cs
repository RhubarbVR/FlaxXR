using Flax.Build;
using Flax.Build.NativeCpp;
using System.IO;

public class FlaxXRPlugin : GameModule
{
    /// <inheritdoc />
    public override void Setup(BuildOptions options)
    {
        base.Setup(options);

        BuildNativeCode = true;
        options.PublicDefinitions.Add("COMPILE_WITH_FLAX");
        var openxrPath = Path.GetFullPath(Path.Combine(FolderPath, "..", "..", "OpenXR"));
        options.CompileEnv.IncludePaths.Add(Path.Combine(openxrPath, "include"));
        var nativeFolder = Path.Combine(openxrPath, "native");
        string platformString = null;
        var arc = options.Architecture;
        var targetPLatform = options.Platform.Target;
        switch (targetPLatform)
        {
            case TargetPlatform.Windows:
                switch (arc)
                {
                    case TargetArchitecture.x86:
                        platformString = Path.Combine("Windows", "Win32");
                        break;
                    case TargetArchitecture.x64:
                        platformString = Path.Combine("Windows", "x64");
                        break;
                    default:
                        break;
                }
                break;
            case TargetPlatform.UWP:
                switch (arc)
                {
                    case TargetArchitecture.x86:
                        platformString = Path.Combine("Windows", "Win32_uwp");
                        break;
                    case TargetArchitecture.ARM:
                        platformString = Path.Combine("Windows", "ARM_uwp");
                        break;
                    case TargetArchitecture.ARM64:
                        platformString = Path.Combine("Windows", "ARM64_uwp");
                        break;
                    default:
                        break;
                }
                break;
            case TargetPlatform.Android:
                switch (arc)
                {
                    case TargetArchitecture.x86:
                        platformString = Path.Combine("Android", "x86");
                        break;
                    case TargetArchitecture.x64:
                        platformString = Path.Combine("Android", "x86_64");
                        break;
                    case TargetArchitecture.ARM:
                        platformString = Path.Combine("Android", "armeabi-v7a");
                        break;
                    case TargetArchitecture.ARM64:
                        platformString = Path.Combine("Android", "arm64-v8a");
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
        options.PublicDependencies.Add("Graphics");
        options.PublicDependencies.Add("GraphicsDeviceNull");
        options.PublicDependencies.Add("GraphicsDeviceDX11");
        options.PublicDependencies.Add("GraphicsDeviceDX12");
        if (targetPLatform != TargetPlatform.UWP)
        {
            options.PublicDependencies.Add("GraphicsDeviceVulkan");
            options.PrivateDependencies.Add("volk");
            options.PrivateDependencies.Add("VulkanMemoryAllocator");
            string includesFolderPath;
            if (VulkanSdk.Instance.TryGetIncludePath(out includesFolderPath))
            {
                options.PublicIncludePaths.Add(includesFolderPath);
            }
            else
            {
                Log.Error("Missing VulkanSDK.");
            }
        }


        options.PublicDependencies.Add("Render2D");
        options.PublicDependencies.Add("Renderer");

        if (platformString == null)
        {
            return;
        }

        options.CompileEnv.PreprocessorDefinitions.Add("OPENXR_SUPPORT");

        var platformFolder = Path.Combine(nativeFolder, platformString);
        if (targetPLatform == TargetPlatform.Android)
        {
            options.DependencyFiles.Add(Path.Combine(platformFolder, "libopenxr_loader.so"));
        }
        else
        {
            options.DependencyFiles.Add(Path.Combine(platformFolder, "bin", "openxr_loader.dll"));
            options.LinkEnv.InputLibraries.Add(Path.Combine(platformFolder, "lib", "openxr_loader.lib"));
        }


    }
}
