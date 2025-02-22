/* See LICENSE file for copyright and license details. */

/* appearance */
// Colors have been matched to i3 & i3bar
static const char* normbgcolor  = "#222222";
static const char* normfgcolor  = "#888888";
static const char* selbgcolor   = "#285577";
static const char* selfgcolor   = "#ffffff";
static const char* urgbgcolor   = "#900000";
static const char* urgfgcolor   = "#ffffff";
static const char font[]        = "monospace:size=9";
static const char before[]      = "<";
static const char after[]       = ">";
static const char titletrim[]   = "...";
static const int  tabwidth      = 200;
static const Bool foreground    = True;
static       Bool urgentswitch  = False;

/*
 * Where to place a new tab when it is opened. When npisrelative is True,
 * then the current position is changed + newposition. If npisrelative
 * is False, then newposition is an absolute position.
 */
static int  newposition   = -1;
static Bool npisrelative  = False;

#define SETPROP(p) { \
        .v = (char *[]){ "/bin/sh", "-c", \
                "prop=\"`xwininfo -children -id $1 | grep '^     0x' |" \
                "sed -e's@^ *\\(0x[0-9a-f]*\\) \"\\([^\"]*\\)\".*@\\1 \\2@' |" \
                "xargs -0 printf %b | dmenu -l 10 -w $1`\" &&" \
                "xprop -id $1 -f $0 8s -set $0 \"$prop\"", \
                p, winid, NULL \
        } \
}

#define MODKEY ControlMask
static const Key keys[] = {
  // All matching modifiers are run in the order they appear here.
	/* modifier             key        function     argument */

  // focusonce ensures that "rotate 0" works correctly with spawn.
	{ MODKEY,               XK_t,      focusonce,   { 0 } },
	{ MODKEY,               XK_t,      spawn,       { 0 } },

  // '.i = 0' causes rotate to switch to the 'last active'
	{ MODKEY,               XK_Tab,    rotate,      { .i = +1 } },
	{ MODKEY|ShiftMask,     XK_Tab,    rotate,      { .i = -1 } },
	{ MODKEY|ShiftMask,     XK_Left,   movetab,     { .i = -1 } },
	{ MODKEY|ShiftMask,     XK_Right,  movetab,     { .i = +1 } },

	//{ MODKEY,               XK_grave,  spawn,       SETPROP("_TABBED_SELECT_TAB") },
	{ MODKEY,               XK_1,      move,        { .i = 0 } },
	{ MODKEY,               XK_2,      move,        { .i = 1 } },
	{ MODKEY,               XK_3,      move,        { .i = 2 } },
	{ MODKEY,               XK_4,      move,        { .i = 3 } },
	{ MODKEY,               XK_5,      move,        { .i = 4 } },
	{ MODKEY,               XK_6,      move,        { .i = 5 } },
	{ MODKEY,               XK_7,      move,        { .i = 6 } },
	{ MODKEY,               XK_8,      move,        { .i = 7 } },
	{ MODKEY,               XK_9,      move,        { .i = 8 } },
	{ MODKEY,               XK_0,      move,        { .i = 9 } },

  // Kept around incase terminal runs amuck.
	{ MODKEY|ShiftMask,     XK_q,      killclient,  { 0 } },

	//{ MODKEY,               XK_u,      focusurgent, { 0 } },
	//{ MODKEY|ShiftMask,     XK_u,      toggle,      { .v = (void*) &urgentswitch } },

	//{ 0,                    XK_F11,    fullscreen,  { 0 } },
};
