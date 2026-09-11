# ===== 编译器与选项 =====
CXX      ?= g++
CXXFLAGS ?= -std=c++11 -Wall -O2
LDFLAGS  ?=

# ===== 源文件 =====
SRCS   := start.cpp LeetCode.cpp
OBJS   := $(SRCS:.cpp=.o)
TARGET := start

# ===== 扫描题目头文件（自动发现，无需手动维护） =====
# code1-100/xxx.h、code2501-2600/xxx.h ... 以及 AdventureMode 下的头文件
PROBLEM_HDRS := $(shell find code* -name '*.h' 2>/dev/null) \
                $(shell find AdventureMode -name '*.h' 2>/dev/null)

.PHONY: all clean

# 默认目标
all: $(TARGET)

# ===== 自动生成聚合头 all_problems.h =====
# 依赖所有题目头文件；任一题目文件变化都会触发生成
all_problems.h: $(PROBLEM_HDRS)
	@echo "#pragma once" > $@
	@for f in $(sort $(PROBLEM_HDRS)); do echo '#include "'$$f'"' >> $@; done
	@echo "已生成 all_problems.h, 共 $(words $(PROBLEM_HDRS)) 个题目头文件"

# ===== 编译规则 =====
# start.o 依赖 all_problems.h，保证生成顺序
start.o: start.cpp all_problems.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

LeetCode.o: LeetCode.cpp LeetCode.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ===== 链接 =====
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# ===== 清理 =====
clean:
	rm -f $(OBJS) $(TARGET) all_problems.h
