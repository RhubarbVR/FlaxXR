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

        /// <inheritdoc />
        public override void Initialize()
        {
            base.Initialize();

            Debug.Log("Hello from plugin code!");
        }

        /// <inheritdoc />
        public override void Deinitialize()
        {
            // Use it to cleanup data

            base.Deinitialize();
        }
    }
}
