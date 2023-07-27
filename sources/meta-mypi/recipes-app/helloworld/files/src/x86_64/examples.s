
            .global getInt
            .global add
            .global callback
            .extern cFunction

            //getInt():int
getInt:     mov $16,%eax
            ret

            //add(int a, int b):int
add:        mov %edi,%eax
            mov %esi,%ecx
            add %ecx,%eax
            ret

callback:   call cFunction
            ret

            .section .note.GNU-stack
            

