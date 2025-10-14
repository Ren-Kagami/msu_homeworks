import subprocess
import os

def compile_c_program(source_file="weights.c", output_file="weights"):
    """Компилирует C программу"""
    result = subprocess.run(
        ["gcc", "-std=c99", "-o", output_file, source_file],
        capture_output=True,
        text=True
    )
    if result.returncode != 0:
        print("Ошибка компиляции:")
        print(result.stderr)
        return False
    return True

def run_test(executable, input_value):
    """Запускает программу с заданным входом"""
    try:
        result = subprocess.run(
            [f"./{executable}"],
            input=str(input_value),
            capture_output=True,
            text=True,
            timeout=5
        )
        return int(result.stdout.strip())
    except subprocess.TimeoutExpired:
        return None
    except ValueError:
        return None

def reference_solution(n):
    """Эталонное решение на Python"""
    m = -1
    for i in range(32):
        c = 0
        t = n
        for j in range(32):
            if t % 3 == 1:
                c += 1
                t = (t - 1) // 3
            elif t % 3 == 2:
                c += 1
                t = (t + 1) // 3
            else:
                t //= 3
        if t == 0 and (m == -1 or c < m):
            m = c
    return m

def run_tests():
    """Запускает набор тестов"""

    # Компилируем программу
    print("Компиляция программы...")
    if not compile_c_program():
        return
    print("✓ Компиляция успешна\n")

    # Набор тестов
    test_cases = [
        # Базовые случаи
        (1, "Минимальное значение"),
        (2, "Вычитание: 3 - 1"),
        (3, "Степень тройки"),
        (4, "Сумма: 3 + 1"),
        (5, "5 = 9 - 3 - 1"),

        # Степени тройки
        (9, "3^2"),
        (27, "3^3"),
        (81, "3^4"),
        (243, "3^5"),
        (729, "3^6"),
        (2187, "3^7"),
        (6561, "3^8"),
        (19683, "3^9"),
        (59049, "3^10"),

        # Граничные степени тройки
        (3**15, "3^15"),
        (3**18, "3^18"),
        (3**19, "3^19 (близко к лимиту)"),

        # Средние значения
        (100, "Сотня"),
        (1000, "Тысяча"),
        (10000, "Десять тысяч"),
        (100000, "Сто тысяч"),
        (1000000, "Миллион"),
        (10000000, "Десять миллионов"),
        (100000000, "Сто миллионов"),

        # Числа с максимальным количеством гирь
        (682, "Много гирь (сбалансированная троичная)"),
        (2046, "Много гирь"),
        (6138, "Много гирь"),

        # Крайние случаи
        (999999999, "Максимум - 1"),
        (1000000000, "Максимум по условию"),

        # Особые случаи
        (3**19 - 1, "3^19 - 1"),
        (3**19 + 1, "3^19 + 1"),
        ((3**19 - 1) // 2, "Много ненулевых разрядов"),
    ]

    print("=" * 80)
    print(f"{'Вход':<15} {'Ожидаемый':<12} {'Полученный':<12} {'Статус':<10} {'Описание'}")
    print("=" * 80)

    passed = 0
    failed = 0

    for n, description in test_cases:
        if n > 1000000000:
            continue

        expected = reference_solution(n)
        actual = run_test("weights", n)

        if actual is None:
            status = "⚠ TIMEOUT"
            failed += 1
        elif actual == expected:
            status = "✓ PASS"
            passed += 1
        else:
            status = "✗ FAIL"
            failed += 1

        print(f"{n:<15} {expected:<12} {actual if actual else 'N/A':<12} {status:<10} {description}")

    print("=" * 80)
    print(f"\nРезультаты: {passed} пройдено, {failed} провалено из {passed + failed} тестов")

    # Дополнительные проверки переполнения
    print("\n" + "=" * 80)
    print("Проверка на переполнение и граничные случаи:")
    print("=" * 80)

    overflow_tests = [
        (2**31 - 1, "Максимум int32"),
        (2**32 - 1, "Максимум uint32 (если бы не ограничение)"),
    ]

    for n, desc in overflow_tests:
        if n > 1000000000:
            print(f"{desc}: {n} - за пределами условия задачи")
        else:
            expected = reference_solution(n)
            actual = run_test("weights", n)
            status = "✓" if actual == expected else "✗"
            print(f"{status} {desc}: n={n}, ожидается={expected}, получено={actual}")

    # Тест производительности
    print("\n" + "=" * 80)
    print("Тест производительности (время выполнения):")
    print("=" * 80)

    import time

    perf_tests = [1, 1000, 1000000, 100000000, 1000000000]
    for n in perf_tests:
        start = time.time()
        result = run_test("weights", n)
        elapsed = time.time() - start
        print(f"n={n:<10} → результат={result:<3} за {elapsed*1000:.2f} мс")

    # Очистка
    if os.path.exists("weights"):
        os.remove("weights")
        print("\n✓ Временные файлы удалены")

if __name__ == "__main__":
    # Создаем C файл если его нет
    c_code = '''#include <stdio.h>

int main(void) {
    long long n, c, t, i, j, m = -1;
    scanf("%lld", &n);

    for (i = 0; i < 32; ++i) {
        c = 0;
        t = n;
        for (j = 0; j < 32; ++j) {
            if (j == i) {
                if (t % 3 == 1) {
                    ++c;
                    t = (t - 1) / 3;
                } else if (t % 3 == 2) {
                    ++c;
                    t = (t + 1) / 3;
                } else {
                    t /= 3;
                }
            } else {
                if (t % 3 == 1) {
                    ++c;
                    t = (t - 1) / 3;
                } else if (t % 3 == 2) {
                    ++c;
                    t = (t + 1) / 3;
                } else {
                    t /= 3;
                }
            }
        }
        if (t == 0 && (m == -1 || c < m))
            m = c;
    }

    printf("%lld\\n", m);
    return 0;
}
'''

    with open("weights.c", "w") as f:
        f.write(c_code)

    try:
        run_tests()
    finally:
        if os.path.exists("weights.c"):
            os.remove("weights.c")