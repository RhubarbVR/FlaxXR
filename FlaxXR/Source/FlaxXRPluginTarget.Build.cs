using Flax.Build;

public class FlaxXRPluginTarget : GameProjectTarget
{
    /// <inheritdoc />
    public override void Init()
    {
        base.Init();

        // Reference the modules for game
        Modules.Add("FlaxXRPlugin");
    }
}
