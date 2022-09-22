using System;
using FlaxEngine;

namespace FlaxXRPlugin
{
    /// <summary>
    /// The sample game plugin.
    /// </summary>
    /// <seealso cref="FlaxEngine.GamePlugin" />
    public class FlaxXR : GamePlugin
    {
        /// <inheritdoc />
        public FlaxXR()
        {
            _description = new PluginDescription
            {
                Name = "FlaxXR",
                Category = "Other",
                Author = "Faolan",
                AuthorUrl = null,
                HomepageUrl = null,
                RepositoryUrl = "https://github.com/RhubarbVR/FlaxXR",
                Description = "This is XR plugin.",
                Version = new Version(1, 0),
                IsAlpha = false,
                IsBeta = true,
            };
        }

        /// <summary>
        /// Tells if OpenXR is supported on the current platform
        /// </summary>
        public static bool OpenXRSupported { get; private set; }
        /// <summary>
        /// Tells if OpenXR is running
        /// </summary>
        public static bool OpenXRRunning { get; private set; }
        /// <summary>
        /// Gets error msg of openxr for debug
        /// </summary>
        public static string MSG => FlaxOpenXR.OpenXRInstanceMSG(_mainOpenXRInst);

       /// <summary>
       /// Notifies if openxr is running or stopped
       /// </summary>
       public static event Action<bool> OpenXRStateChange;

        private static IntPtr _mainOpenXRInst;

        private static void NotifyStateChange(bool state)
        {
            OpenXRRunning = state;
            OpenXRStateChange?.Invoke(state);
        }

        /// <summary>
        /// Starts up OpenXR
        /// </summary>
        /// <returns>If OpenXR was started</returns>
        public static bool InitOpenXR()
        {
            if(_mainOpenXRInst == IntPtr.Zero)
            {
                _mainOpenXRInst = FlaxOpenXR.BuildOpenXRInstance();
            }
            var state = FlaxOpenXR.InitOpenXRInstance(_mainOpenXRInst);
            NotifyStateChange(state);
            return state;
        }

        /// <inheritdoc />
        public override void Initialize()
        {
            base.Initialize();
            OpenXRSupported = FlaxOpenXR.IsOpenXRSupported();
            if (OpenXRSupported)
            {
                Debug.Log("OpenXR Supported");
                _mainOpenXRInst = FlaxOpenXR.BuildOpenXRInstance();
#if !FLAX_EDITOR
                InitOpenXR();
#endif
            }
            else
            {
                Debug.Log("OpenXR not Supported on this platform");
                NotifyStateChange(false);
            }
        }

        /// <inheritdoc />
        public override void Deinitialize()
        {
            // Use it to cleanup data

            base.Deinitialize();
        }
    }
}
