include ../Makefile.inc

# Исходные файлы
SOURCES = main.cpp qsort.cpp bubblesort.cpp
TEST_SOURCES = tests.cpp qsort.cpp bubblesort.cpp

# Объектные файлы
RELEASE_OBJS = $(SOURCES:.cpp=.r.o)
DEBUG_OBJS = $(SOURCES:.cpp=.d.o)
TEST_OBJS = $(TEST_SOURCES:.cpp=.d.o)

# Цели (имена исполняемых файлов)
release: sort_demo
debug: sort_demo_debug
utest: run_tests

# Сборка release версии
sort_demo: $(RELEASE_OBJS)
	$(LD) -o $@ $^

# Сборка debug версии  
sort_demo_debug: $(DEBUG_OBJS)
	$(LD) -o $@ $^

# Сборка тестового исполняемого файла
test_runner: $(TEST_OBJS)
	$(LD) -o $@ $^ $(GTEST_LIBS)

# Запуск unit тестов
run_tests: test_runner
	./test_runner

# Запуск интеграционных тестов
run_itest: sort_demo_debug
	echo "Integration tests..."
	./sort_demo_debug

# Правила компиляции
%.r.o: %.cpp
	$(CXX) $(CXXFLAGS_RELEASE) -c $< -o $@

%.d.o: %.cpp
	$(CXX) $(CXXFLAGS_DEBUG) -c $< -o $@

# Очистка
clean:
	rm -f *.r.o *.d.o sort_demo sort_demo_debug test_runner

# Генерация зависимостей
depends:
	$(CXX) -MM *.cpp > Makefile.hdrdep

# Включение зависимостей
-include Makefile.hdrdep

all: clean depends release run_tests run_itest

.PHONY: all clean run_tests run_itest depends release debug utest