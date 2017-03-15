#include	<assert.h>
#include	<stdio.h>
#include	<string.h>

/*
** Prevent gcc to make optimisations
*/

static char *lambda(char *c)
{
  return c;
}

static int return0()
{
  return 0;
}

void test_strlen()
{
  printf("%ld\n", strlen(lambda("")));
  assert(strlen(lambda("")) == 0);
  //printf("%ld\n", strlen(lambda("oui")));
  assert(strlen(lambda("oui")) == 3);
}

void test_strchr()
{
  printf("%s \n", strchr(lambda(""), 'G'));
  assert(strchr(lambda(""), 'G') == 0);
  //printf("%s \n", strchr(lambda("\"Oui.\" - Gandhi"), 'G'));
  assert(*strchr(lambda("\"Oui.\" - Gandhi"), 'G') == 'G');
  //printf("%s \n", strchr(lambda("\"Oui.\" - Gandhi"), '\0'));
  assert(*strchr(lambda("\"Oui.\" - Gandhi"), '\0') == '\0');
}

void test_memset()
{
  char c[10];

  c[9] = '\0';
  printf("%s \n", (char *)memset(c, 'a', 9));
  assert(strcmp(memset(c, 'a', 9), "aaaaaaaaa") == 0);
}

void test_memcpy()
{
  char c[10];

  c[9] = '\0';
  printf("memcpy\n");
  assert(memcpy(c, "abcdefghi", 9) == c);
  printf("%s \n", c);
  //assert(strcmp(c, lambda("abcdefghi")) == 0);
}

void test_strcmp()
{
  puts("strcmp");
  assert(strcmp(lambda(""), "") == 0);
  assert(strcmp(lambda("abcdef"), "abcdef") == 0);
  assert(strcmp(lambda("ab"), "a") == 'b');
  assert(strcmp(lambda("a"), "ab") == -'b');
  assert(strcmp(lambda("ac"), "ab") == 'c' - 'b');
  assert(strcmp(lambda("ab"), "ac") == 'b' - 'c');
}

void test_memmove()
{
  char s[10];

  puts("memmove\n");
  memcpy(s, "abcdefghi", 10);
  //printf("%s\n", s);
  memmove(s + 1, s, 8);
  //printf("%s\n", s);
  assert(strcmp(s, "aabcdefgh") == 0);
  memmove(s, s + 1, 9);
  //printf("%s\n", s);
  assert(strcmp(s, "abcdefgh") == 0);
}

void test_strncmp()
{
  puts("strncmp");
  assert(strncmp(lambda("z"), lambda("a"), return0()) == 0);
  assert(strncmp(lambda("a"), lambda("a"), 1) == 0);
  //printf("%d\n", strncmp(lambda("za"), lambda("aa"), 1));
  assert(strncmp(lambda("z"), lambda("a"), 1) == 'z' - 'a');
}

void test_strcasecmp()
{
  puts("strcasecmp\n");
  //printf("%d\n", strcasecmp(lambda("aZw"), lambda("AzW")));
  assert(strcasecmp(lambda("aZw"), "AzW") == 0);
  //printf("%d\n", strcasecmp(lambda("a"), lambda("Z")));
  assert(strcasecmp(lambda("AZw"), "ZaW") == 'a' - 'z');
  //printf("%d\n", strcasecmp(lambda("A"), lambda("[")));
  assert(strcasecmp(lambda("A"), lambda("[")) == 'a' - '[');
}

void test_rindex()
{
  const char *s = "\"Oui.\" - Gandhi";

  puts("rindex\n");
  //printf("%ld\n", rindex(s, 'i') - s);
  assert(rindex(s, 'i') == s + 14);
  //printf("%ld\n", rindex(s, 'w'));
  assert(rindex(s, 'w') == NULL);
  //printf("%ld\n", rindex(s, '\0') - s);
  assert(rindex(s, '\0') == s + 15);
}

void test_strstr()
{
  char *s = "\"Oui.\" - Gandhi";

  puts("strstr\n");
  //printf("%s \n", strstr(lambda(s), "i."));
  assert(strstr(lambda(s), "i.") == s + 3);
  //printf("%s \n", strstr(lambda(s), "w"));
  assert(strstr(lambda(s), "w") == NULL);
}

void test_strpbrk()
{
  char *s = "Oui";

  puts("strpbrk\n");
  //printf("%s \n", strpbrk(lambda(s), "qwe"));
  assert(strpbrk(lambda(s), "qwe") == NULL);
  //printf("%s \n", strpbrk(lambda(s), "qweu"));
  assert(strpbrk(lambda(s), "qweu") == s + 1);
}

void test_strcspn()
{
  char *s = "Oui";

  puts("strcspn\n");
  assert(strcspn(lambda(s), "u") == 1);
  assert(strcspn(lambda(s), "zO") == 0);
  assert(strcspn(lambda(s), "zwertw") == 3);
}

int main()
{
  test_strlen();
  test_strchr();
  test_strcmp();
  test_memset();
  test_memcpy();
  test_memmove();
  test_strncmp();
  test_strcasecmp();
  test_rindex();
  test_strstr();
  test_strpbrk();
  test_strcspn();
  return 0;
}

