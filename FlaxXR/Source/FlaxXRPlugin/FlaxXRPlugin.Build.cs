using Flax.Build;
using Flax.Build.NativeCpp;

public class FlaxXRPlugin : GameModule
{
    /// <inheritdoc />
    public override void Setup(BuildOptions options)
    {
        base.Setup(options);


        BuildNativeCode = true;
        options.PublicDefinitions.Add("COMPILE_WITH_FLAX");
    }
}
