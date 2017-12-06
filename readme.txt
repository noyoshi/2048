
 - the gfx_event_waiting() function now returns the following int values based on various events:
     0 :  no event
     1 :  for a key press
     2 :  for a key release
     3 :  for a mouse click
     4 :  for a mouse release
     5 :  for a mouse motion

   note that while gfx_event_waiting() detects one of the above events,
    the gfx_wait() function can still be used to identify which key or
    which mouse button was used.

 - you can change the cursor (mouse pointer) with the gfx_changecursor() function
     possible curses can be found at:
       /usr/include/X11/cursorfont.h 

 - the font can be changed with gfx_changefont(). installed fonts are machine dependent.
     font names and aliases can be found at:
       /usr/share/X11/fonts/misc/fonts.dir
       /usr/share/X11/fonts/misc/fonts.alias

