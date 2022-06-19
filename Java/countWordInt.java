package Java;
import java.util.*;
import java.lang.String;

public class countWordInt{
    public static void main(String[] args){
        String str = "I will give u 10 and 7.5 marks for this extra work";

        int n = str.length();
        int prev = 0, next = 0, icount = 0, wcount = 0, fcount = 0;
        boolean flag = false;
        for(int i = 0; i < n; i++){
            if(i == n - 1)
            {
                next = n;
                flag = true;
            }

            if(str.charAt(i) == ' ')
            {
                next = i; 
                flag = true;
            }

            if(flag){
                try{
                    String temp = str.substring(prev, next);
                    int nu = Integer.parseInt(temp); //may throw error
                    // System.out.println(nu);
                    icount++;
                    
                    flag = false;
                    prev = next + 1;
                    
                }
                catch(NumberFormatException ne){
                    String temp = str.substring(prev, next);
                    
                    try{
                        float f = Float.parseFloat(temp);
                        // System.out.println(f);
                        fcount++;
                        
                        flag = false;
                        prev = next + 1;
                    }
                    catch(Exception e){
                        // System.out.println(temp);
                        wcount++;
                        flag = false;
                        prev = next + 1;
                    }
                }
                
            }
            
        }
        System.out.println(icount+" "+fcount+" "+wcount);
    }
}