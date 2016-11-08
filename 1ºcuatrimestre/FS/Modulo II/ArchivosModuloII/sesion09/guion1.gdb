break 15
run
info locals
p/x $pc
p/x $sp
break 29
next
info locals
p/x $pc
p/x $sp
break 42
next
info locals
p/x $pc
p/x $sp
break 47 
next
info locals
p/x $pc
p/x $sp

delete breakpoints 2 3 4
