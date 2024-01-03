int ft_strlen(char *str)
{
    int i = 0;
    while (str[i++]);
    return i;
}

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
    unsigned int i = 0;
    while (i != size - 1 && i != ft_strlen(src))
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    if (i == ft_strlen(src)){
        return i - 1;
    }
    return i;
}



/*
#include <bsd/string.h>
#ifndef HAVE_STRLCAT
size_t                  
strlcat(char       *dst,        
              const char *src,      
          size_t     size)      
{
  size_t    srclen;         
  size_t    dstlen;         


  dstlen = strlen(dst);
  size   -= dstlen + 1;

  if (!size)
    return (dstlen);        


  srclen = strlen(src);


  if (srclen > size)
    srclen = size;

  memcpy(dst + dstlen, src, srclen);
  dst[dstlen + srclen] = '\0';

  return (dstlen + srclen);
}
#endif 

#ifndef HAVE_STRLCPY

size_t                 
strlcpy(char       *dst,       
              const char *src,     
          size_t      size)    
{
  size_t    srclen;   

  size --;

  srclen = strlen(src);

  if (srclen > size)
    srclen = size;

  memcpy(dst, src, srclen);
  dst[srclen] = '\0';

  return (srclen);
}
#endif
#include <stdio.h>
int main()
{
    char src[30] = "coucou lee lee";
    char dest[30]  = "jean jean";
    printf("src : %s, dest: %s\n", src, dest);
    printf("%d\n", ft_strlcpy(dest, src, 5));
    printf("src : %s, dest: %s\n", src, dest);
    return 0;
}
*/