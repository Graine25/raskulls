
// skull - ReXGlue Recompiled Project
//
// This file is yours to edit. 'rexglue migrate' will NOT overwrite it.
// Customize your app by overriding virtual hooks from rex::ReXApp.

#pragma once

#include <rex/filesystem.h>
#include <rex/rex_app.h>

class SkullApp : public rex::ReXApp {
 public:
  using rex::ReXApp::ReXApp;

  static std::unique_ptr<rex::ui::WindowedApp> Create(
      rex::ui::WindowedAppContext& ctx) {
    return std::unique_ptr<SkullApp>(new SkullApp(ctx, "skull",
        PPCImageConfig));
  }

  // Override virtual hooks for customization:
  std::optional<rex::PathConfig> OnFinalizePaths(
      const rex::PathConfig& defaults,
      std::function<void(rex::PathConfig)> resume) override {
    (void)resume;
    rex::PathConfig paths = defaults;
    const std::string root = rex::cvar::GetFlagByName("ras_data_root");
    if (!root.empty()) {
      std::filesystem::path resolved = rex::to_path(root);
      if (resolved.is_relative()) {
        resolved = std::filesystem::weakly_canonical(
            rex::filesystem::GetExecutableFolder() / resolved);
      }
      paths.game_data_root = resolved;
    }
    return paths;
  }

  // void OnPostInitLogging() override {}
  // void OnPreSetup(rex::RuntimeConfig& config) override {}
  // void OnLoadXexImage(std::string& xex_image) override {}
  // void OnPostSetup() override {}
  // void OnCreateDialogs(rex::ui::ImGuiDrawer* drawer) override {}
  // void OnShutdown() override {}
  // void OnConfigurePaths(rex::PathConfig& paths) override {}
};
