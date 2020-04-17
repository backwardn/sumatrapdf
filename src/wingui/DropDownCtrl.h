/* Copyright 2020 the SumatraPDF project authors (see AUTHORS file).
   License: Simplified BSD (see COPYING.BSD) */

struct DropDownCtrl;

struct DropDownSelectionChangedEvent : WndEvent {
    DropDownCtrl* dropDown = nullptr;
    int idx = 0;
    std::string_view item;
};

typedef std::function<void(DropDownSelectionChangedEvent*)> DropDownSelectionChangedHandler;

struct DropDownCtrl : WindowBase {
    Vec<std::string_view> items;
    DropDownSelectionChangedHandler onDropDownSelectionChanged = nullptr;

    DropDownCtrl(HWND parent);
    ~DropDownCtrl();
    bool Create() override;

    void HandleWM_COMMAND(WndEvent*);

    SizeI GetIdealSize() override;

    void SetCurrentSelection(int n);
    int GetCurrentSelection();
    void SetItems(Vec<std::string_view>& newItems);
    void SetCueBanner(std::string_view);
};

ILayout* NewDropDownLayout(DropDownCtrl* b);

bool IsDropDown(Kind);
bool IsDropDown(ILayout*);
