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

            _button = Editor.UI.ToolStrip.AddButton("Start VR", VRStartStop);
            FlaxXR.OpenXRStateChange += FlaxXR_OpenXRStateChange;
            FlaxXR_OpenXRStateChange(FlaxXR.OpenXRRunning);
        }

        private void VRStartStop()
        {
            if (FlaxXR.OpenXRRunning)
            {

            }
            else
            {
                if (!FlaxXR.InitOpenXR())
                {
                    MessageBox.Show($"Failed to start VR headset probably not connected\nError:{FlaxXR.MSG}");
                }
            }
        }

        private void FlaxXR_OpenXRStateChange(bool obj)
        {
            _button.Text = obj ? "Stop VR" : "Start VR";
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
