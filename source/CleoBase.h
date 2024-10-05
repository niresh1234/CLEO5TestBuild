#pragma once

#include "CCodeInjector.h"
#include "CGameVersionManager.h"
#include "CDebug.h"
#include "CDmaFix.h"
#include "CGameMenu.h"
#include "CModLoaderSystem.h"
#include "CModuleSystem.h"
#include "CPluginSystem.h"
#include "CScriptEngine.h"
#include "CCustomOpcodeSystem.h"
#include "FileEnumerator.h"
#include "crc32.h"
#include "OpcodeInfoDatabase.h"

namespace CLEO
{
    class CCleoInstance
    {
    public:
        enum InitStage : size_t
        {
            None,
            Initial,
            OnDraw,
            Done = OnDraw
        };

        // order here defines init and deinit order!
        CDmaFix					DmaFix;
        CGameMenu				GameMenu;
        CCodeInjector			CodeInjector;
        CPluginSystem			PluginSystem;
        CGameVersionManager		VersionManager;
        CScriptEngine			ScriptEngine;
        CCustomOpcodeSystem		OpcodeSystem;
        CModuleSystem			ModuleSystem;
        CModLoaderSystem		ModLoader;
        OpcodeInfoDatabase		OpcodeInfoDb;

        int saveSlot = -1; // -1 if not loaded from save

        CCleoInstance() = default;
        virtual ~CCleoInstance();

        void Start(InitStage stage);
        void Stop();

        void GameBegin();
        void GameEnd();

        bool IsStarted() const { return m_initStage != InitStage::None; }

        void AddCallback(eCallbackId id, void* func);
        void RemoveCallback(eCallbackId id, void* func);
        const std::set<void*>& GetCallbacks(eCallbackId id);
        void CallCallbacks(eCallbackId id);
        void CallCallbacks(eCallbackId id, DWORD arg);

        static void __cdecl OnDrawingFinished();

        void(__cdecl * UpdateGameLogics)() = nullptr;
        static void __cdecl OnUpdateGameLogics();

        // call for InitInstance
        HWND(__cdecl* CreateMainWnd_Orig)(HINSTANCE) = nullptr;
        static HWND __cdecl OnCreateMainWnd(HINSTANCE hinst);

        // main window procedure hook
        LRESULT(__stdcall* MainWndProc_Orig)(HWND, UINT, WPARAM, LPARAM) = nullptr;
        static LRESULT __stdcall OnMainWndProc(HWND, UINT, WPARAM, LPARAM);

        // calls to CTheScripts::Init
        void(__cdecl* ScmInit1_Orig)() = nullptr;
        void(__cdecl* ScmInit2_Orig)() = nullptr;
        void(__cdecl* ScmInit3_Orig)() = nullptr;
        static void OnScmInit1();
        static void OnScmInit2();
        static void OnScmInit3();

        // call for Game::Shutdown
        void(__cdecl* GameShutdown)() = nullptr;
        static void OnGameShutdown();

        // calls for Game::ShutDownForRestart
        void(__cdecl* GameRestart1)() = nullptr;
        void(__cdecl* GameRestart2)() = nullptr;
        void(__cdecl* GameRestart3)() = nullptr;
        static void OnGameRestart1();
        static void OnGameRestart2();
        static void OnGameRestart3();

        // empty function called after everything else is drawn
        memory_pointer DebugDisplayTextBuffer = nullptr;
        static void OnDebugDisplayTextBuffer();

    private:
        InitStage m_initStage = InitStage::None;
        bool m_bGameInProgress;
        std::map<eCallbackId, std::set<void*>> m_callbacks;
    };

    CCleoInstance& GetInstance();
}

