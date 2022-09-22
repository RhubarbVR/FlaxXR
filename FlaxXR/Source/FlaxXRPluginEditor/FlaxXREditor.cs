using System;
using FlaxEditor;
using FlaxEditor.GUI;
using FlaxEngine;

namespace FlaxXRPlugin
{
	/// <summary>
	/// The sample editor plugin using <see cref="FlaxXR"/>.
	/// </summary>
	/// <seealso cref="FlaxEditor.EditorPlugin" />
	public class FlaxXREditor : EditorPlugin
    {
        private ToolStripButton _button;

        /// <inheritdoc />
        public override Type GamePluginType => typeof(FlaxXR);

        /// <inheritdoc />
        public override void InitializeEditor()
        {
            base.InitializeEditor();

            _button = Editor.UI.ToolStrip.AddButton("FlaxXR");
            _button.Clicked += () => MessageBox.Show("Button clicked!");
        }

        /// <inheritdoc />
        public override void Deinitialize()
        {
            if (_button != null)
            {
                _button.Dispose();
                _button = null;
            }

            base.Deinitialize();
        }
    }
}
