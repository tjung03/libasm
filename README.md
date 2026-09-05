# libasm

**문자열 처리와 입출력 함수 6개를 x86-64 어셈블리로 구현한 정적 라이브러리입니다.** 42 Seoul 프로젝트로, 레지스터를 통한 인자 전달·바이트 단위 메모리 접근·시스템 호출·C 함수 연결을 다룹니다.

실행 대상은 **macOS x86-64**이며, NASM의 `macho64` 형식으로 오브젝트를 생성합니다.

## 구현 함수

| 함수 | 주요 구현 |
|---|---|
| [ft_strlen](ft_strlen.s) | NUL 바이트까지 순회하며 `rax`에 길이 누적 |
| [ft_strcpy](ft_strcpy.s) | 원본을 NUL까지 바이트 단위로 복사하고 목적지 주소 반환 |
| [ft_strcmp](ft_strcmp.s) | 두 문자열의 첫 차이 또는 NUL을 찾아 바이트 차이 반환 |
| [ft_strdup](ft_strdup.s) | 길이 계산, `malloc` 호출, 새 메모리에 문자열 복사 |
| [ft_read](ft_read.s) | Darwin `read` syscall과 오류 분기 |
| [ft_write](ft_write.s) | Darwin `write` syscall과 오류 분기 |

## C와 어셈블리 연결

C에서 전달한 인자는 `rdi`·`rsi`·`rdx` 등으로 받아 처리하고, 결과는 `rax`로 반환합니다. `ft_strdup`은 C 런타임의 `_malloc`을 호출하며, 입출력 함수는 Darwin syscall 번호 `0x2000003`·`0x2000004`를 사용합니다.

입출력 오류 분기에서는 carry flag를 확인하고 `___error`로 얻은 주소에 오류값을 기록한 뒤 `-1`을 반환하도록 작성되어 있습니다.

| 파일 | 역할 |
|---|---|
| `ft_*.s` | 6개 함수 구현 |
| [libasm.h](libasm.h) | C에서 사용할 함수 선언 |
| [Makefile](Makefile) | NASM 어셈블·정적 라이브러리 생성 |
| [main.c](main.c) | 기존 표준 함수 비교용 코드 |

## 빌드와 사용

macOS x86-64용 C 도구와 NASM이 필요합니다.

```bash
make
```

생성물은 `libasm.a`입니다. 다음 내용을 로컬 `example.c`에 저장합니다.

```c
#include "libasm.h"

int main(void)
{
    char *copy = ft_strdup("Assembly");
    if (copy == NULL)
        return (1);
    printf("length: %zu\n", ft_strlen(copy));
    printf("copy: %s\n", copy);
    free(copy);
    return (0);
}
```

```bash
cc -arch x86_64 example.c libasm.a -o example
./example
```

문자열 `Assembly`와 길이 `8`을 출력하는 예제입니다. 라이브러리가 할당해 반환한 문자열은 호출자가 해제합니다.

기존 `make test`는 [main.c](main.c)를 빌드하고 실행합니다. 해당 비교 코드에는 해제된 포인터를 출력하는 구문이 있으므로, 함수 사용 확인에는 위처럼 메모리 수명을 지킨 별도 예제를 사용합니다.

## 플랫폼 호환성

| 항목 | 저장소 기준 |
|---|---|
| 아키텍처·문법 | x86-64, NASM Intel 문법 |
| 오브젝트 형식 | Mach-O 64비트, `-f macho64` — [NASM 문서](https://www.nasm.us/doc/nasm09.html) |
| 시스템 호출 | Darwin 번호와 오류 처리 규약 |
| Apple silicon | x86-64 바이너리는 Rosetta 지원 환경 필요 — [Apple 안내](https://developer.apple.com/documentation/apple-silicon/about-the-rosetta-translation-environment) |

Linux 이식에는 ELF 형식·심볼 이름·syscall 번호·오류 처리 규약을 함께 변경해야 합니다. ARM64 네이티브 실행에는 명령어와 호출 규약에 맞는 별도 구현이 필요합니다.

`make clean`은 오브젝트, `make fclean`은 라이브러리와 기존 테스트 실행 파일까지 삭제하며, `make re`는 전체를 다시 빌드합니다.
