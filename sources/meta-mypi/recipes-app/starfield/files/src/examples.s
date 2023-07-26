            .global getInt
            .global add
            
            //getInt():int
getInt:     mov    w0, 16     
            ret

            //add(int a, int b):int
add:        add x0, x0, x1
            ret

