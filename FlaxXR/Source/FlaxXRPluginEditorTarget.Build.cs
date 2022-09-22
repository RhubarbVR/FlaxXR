using Flax.Build;

public class FlaxXRPluginEditorTarget : GameProjectEditorTarget
{
    /// <inheritdoc />
    public override void Init()
    {
        base.Init();

        // Reference the modules for editor
        Modules.Add("FlaxXRPlugin");
        Modules.Add("FlaxXRPluginEditor");
    }
}
