Note for newcomers:

In the shortcuts below, "C" stands for CTRL and "A" stands for "ALT". This is a convention
used in the Midnight Commander documentation and was kept here.

You can also use "ESC" instead of "ALT", which is useful on Macbooks.

Main View
---------------------------------------------------------------
- File/directory operations
    F3                        View file
    Shift + F3                View raw file (disregard extension)
    F5                        Copy selected files
    F6                        Move selected files
    Shift + F6                Rename file under cursor
    Shift-F4                  Create a new file
    C-x d                     Compare directories
    C-x c                     Chmod dialog
    C-x o                     Chown dialog
    C-x C-s                   Edit symlink
    C-x s                     Create symlink dialog
    C-x l                     Create hard link dialog
    C-x v                     Run relative symbolic link tool on selected or tagged items
    C-x a                     List active VFS directories

- Selection
    Insert / C-t              Select/deselect file
    *                         Invert selection on files
    +                         Specify file selection options (including custom pattern)
    -                         Same as above, but for deselecting

- Navigation
    TAB /  / C-i              Jump from one panel to the other
    F9                        Select the top menu bar
    Esc Esc                   Quickly dismiss menus/pop-ups (skip the timeout for "Single press" from the configuration)
    A-c                       Quick cd dialog
    A-?                       Search dialog
    C-s                       Search for item
    A-s                       Incremental search (A-s again to jump to next occurence)
    A-y                       Move to the previous directory in the directory history
    A-u                       Move to the next directory in the directory history
    A-Shift-h                 Show path history
    C-\                       Directory Hotlist
    C-p / Up arrow            Move selection bar to the previous entry in the panel
    C-n / Down arrow          Move selection bar to the next entry in the panel
    A-g                       Move selection bar to the first visible item in the panel
    A-r                       Move selection bar to the middle item in the panel
    A-j                       Move selection bar to the last visible item in the panel
    A-v / Page up             Move selection bar one page up
    A-p / Page down           Move selection bar one page down
    A-< / Home                Move selection bar to the top (first entry)
    A-> / End                 Move selection bar to the bottom (last entry)

- Display
    C-r                       Refresh current panel
    C-u                       Swap panels
    A-,                       Toggle panel layout (horizontal/vertical)
    C-x i                     Toggle other panel to information mode
    C-x q                     Toggle other panel to quick view mode
    A-i                       Make the other panel show the same directory as the current
    A-o                       Display the contents of the highlighted dir in the other panel
    A-t                       Change panel view (full, brief, long)
    A-.                       Toggle "Show Hidden Files" feature

- Command prompt
    C-o                       Drop to the console
    A-Enter                   Put the name of the highlighted file on command line
    C-x t                     Put the name of the selected items on command line
    C-Shift-Enter             Put the full path of the highlighted file on command line
    A-a / C-x p               Put the full path of the pane directory on the command line
    A-h                       Show command history
    A-n / A-p                 Navigate up/down through the command history
    C-x !                     External Panelize (fill current panel with the output of a command)
    C-x j                     Show background jobs
    F2-@                      Run a command on the currently highlighted item, e.g.:
        F2-@ unzip                Unzip selected file
        F2-@ zip -r foo.zip       Zip current directory as foo.zip
        F2-@ 7za x                Extract selected file with 7zip
        F2-@ 7za a foo.7z         7zip current directory as foo.7z

- Others
    Shift-F10                 Quiet exit, without confirmation


File View
---------------------------------------------------------------
    C-f                           View the next file
    C-b                           View the previous file
