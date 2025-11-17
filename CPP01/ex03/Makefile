# ======================== #
#         COLORS           #
# ======================== #
RESET   = \033[0m
RED     = \033[1;31m
GREEN   = \033[1;32m
YELLOW  = \033[1;33m
BLUE    = \033[1;34m
MAGENTA = \033[1;35m
CYAN    = \033[1;36m
WHITE   = \033[1;37m

# ======================== #
#       FLAGS              #
# ======================== #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

NAME = FightClub

# ======================== #
#       PATHS              #
# ======================== #

OBJ_DIR = obj

# ======================== #
#        SRC/OBJ           #
# ======================== #

SRC_FILES = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))

# ======================== #
#        RULES             #
# ======================== #

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "$(GREEN)Compilation successful! ✅$(RESET)"

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)Object files cleaned! ✅$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN)Executable removed! ✅$(RESET)"

re: fclean all

valgrind: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

# ======================== #
#        PHONY             #
# ======================== #

.PHONY: all clean fclean re valgrind
