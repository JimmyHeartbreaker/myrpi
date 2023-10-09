
            .global getInt
            .global add
            .global callback
            .extern cFunction

            //getInt():int
getInt:     mov    w0, 16     
            ret

            //add(int a, int b):int
add:        add x0, x0, x1
            ret

callback:   
            str     x30, [sp, -16]! 
            bl cFunction
            ldr     x30, [sp], 16  
            ret
            

