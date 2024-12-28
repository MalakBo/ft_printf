#include "ft_printf.h"
int ft_putsstr(const char *s, const char c, int n)
{
    int i;
    int num;
    i = 0;
    if(!s && n == 0)
        return(write(1,"(null)",6));
    num = 0;
    if(n == 0)
        return (num+= write(1,&c,1));
    else
    {
        while(s[i] != '\0')
        {
            return(num+= write(1,&s[i],1));
            i++;
        }
    }
    return (num);
}
int ft_printhexa(unsigned long n, char c, int m)
{
    int num;
    char *hexa;
    hexa = "0123456789abcdef";
    num = 0;
    if(c == "X")
        hexa = "0123456789ABCDEF";
    else if(c == "p" && m == 0)
        return(num += write(1, "(nil)",5));
    else if(c == "p" && m == 1)
        num+= write(1, "0x", 2);
    if(n < 16)
        num += write(1, &hexa[n], 1);
    else
    {
        num+= ft_printhexa(n / 16, c ,2);
        num+= ft_printhexa(n % 16, c, 2);
    }
    return (num);
}
int ft_putnbr(long n)
{
    int num;
    char x;
    num = 0;
    if(n < 0)
    {
        num += write(1, "-", 1);
        num += n * -1;
    }
    else if (n > 9)
    {
        num += ft_putnbr(n / 10);
        num += ft_putnbr(n % 10);
    }
    else
    {
        x = n + '0';
        num += write(1, &x, 1);
    }
    return (num);
}
int format_specifier(char spec, va_list argos)
{
    int num;
    char *p;

    num = 0;
    if(spec == 'c')
        num += ft_putsstr(0, va_arg(argos,int),0);
    else if(spec == 's')
        num += ft_putsstr(va_arg(argos,char *),0,1);
    else if(spec == 'p')
    {
        va_arg(argos,void *);
        if(!p)
            num += ft_printhexa(p,spec,0);
        else 
            num += ft_printhexa(p,spec,1);
    }
    else if(spec == 'd' || spec == 'i')
        num += ft_putnbr(va_arg(argos,int));
    else if(spec == 'u')
        num += ft_putnbr(va_arg(argos,unsigned int));
    else if(spec == 'x' || spec == 'X')
        num += ft_printhexa(va_arg(argos,unsigned int),spec,2);
    else if(spec == '%')
        num += ft_putsstr(0,'%',1);
    return (num);

}
int ft_printf(const char *s, ...)
{
    va_list argos;
    int num;
    int i;

    i = 0;
    num = 0;
    if(!s)
        return(-1);
    va_start(argos,s);
    while(s[i] != '\0')
    {
        if(s[i] != '%')
        {
            num += ft_putsstr(0,s[i],1);
            i++;
        }
        else
        {
            if(s[i] == '\0')
                return (va_end(argos),-1);
            num += format_specifier(s[i],argos);
        }
        i++;
    }
    return(va_end(argos),num);
}
int main(void)
{
    ft_printf("Hello, world!\n");
    ft_printf("a number : %d\n",42);
    ft_printf("character : %c\n",'A');
    ft_printf("String : %s\n","khdama");
    ft_printf("Hexadecimal test: %x\n", 255);
    ft_printf("Percemtage : %%\n");
    return (0);
}
