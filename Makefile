BUILD_DIR = object
BUILD_DIR_BONUS = object_bonus
MLX_PATH = ./MLX42
LIBFT_PATH = ./libft
NAME = cub3D
NAME_BONUS = cub3D_bonus

SRC = cub3d.c \
cleanup.c \
./init/validate_input.c \
./init/sanitize_structs.c \
./init/simulation_config.c \
./parsing/map_data_manager.c \
./parsing/config/extract_config.c \
./parsing/config/set_texture.c \
./parsing/config/set_color.c \
./parsing/map/map_dimensions.c \
./parsing/map/map_copy.c \
./parsing/map/map_validation.c \
./parsing/map/map_closure.c \
./parsing/config/validate_config.c \
./parsing/utils/parsing_utils.c \
./parsing/utils/error_handling.c \
./resources/resources_manager.c \
./resources/player_orientation.c \
./resources/color_conversion.c \
./resources/texture_loader.c \
./resources/resources_free.c \
./engine/screen_manager.c \
./engine/engine_loop.c \
./engine/raycasting/render.c \
./engine/raycasting/prepare.c \
./engine/raycasting/dda.c \
./engine/raycasting/texture.c \
./engine/raycasting/draw.c \
./engine/raycasting/utils.c \
./game/input_handler.c \
./game/player_movement.c \
./game/map_collision.c

SRC_BONUS = ./bonus/cub3d_bonus.c \
./bonus/cleanup_bonus.c \
./bonus/init_bonus/validate_input_bonus.c \
./bonus/init_bonus/sanitize_structs_bonus.c \
./bonus/init_bonus/simulation_config_bonus.c \
./bonus/parsing_bonus/map_data_manager_bonus.c \
./bonus/parsing_bonus/config_bonus/extract_config_bonus.c \
./bonus/parsing_bonus/config_bonus/set_texture_bonus.c \
./bonus/parsing_bonus/config_bonus/set_color_bonus.c \
./bonus/parsing_bonus/map_bonus/map_dimensions_bonus.c \
./bonus/parsing_bonus/map_bonus/map_copy_bonus.c \
./bonus/parsing_bonus/map_bonus/map_validation_bonus.c \
./bonus/parsing_bonus/map_bonus/map_closure_bonus.c \
./bonus/parsing_bonus/config_bonus/validate_config_bonus.c \
./bonus/parsing_bonus/utils_bonus/parsing_utils_bonus.c \
./bonus/parsing_bonus/utils_bonus/error_handling_bonus.c \
./bonus/resources_bonus/resources_manager_bonus.c \
./bonus/resources_bonus/player_orientation_bonus.c \
./bonus/resources_bonus/color_conversion_bonus.c \
./bonus/resources_bonus/texture_loader_bonus.c \
./bonus/resources_bonus/resources_free_bonus.c \
./bonus/engine_bonus/screen_manager_bonus.c \
./bonus/engine_bonus/engine_loop_bonus.c \
./bonus/engine_bonus/raycasting_bonus/render_bonus.c \
./bonus/engine_bonus/raycasting_bonus/prepare_bonus.c \
./bonus/engine_bonus/raycasting_bonus/dda_bonus.c \
./bonus/engine_bonus/raycasting_bonus/texture_bonus.c \
./bonus/engine_bonus/raycasting_bonus/draw_bonus.c \
./bonus/engine_bonus/raycasting_bonus/utils_bonus.c \
./bonus/game_bonus/input_handler_bonus.c \
./bonus/game_bonus/mouse_handler_bonus.c \
./bonus/game_bonus/player_movement_bonus.c \
./bonus/game_bonus/map_collision_bonus.c


OBJ = $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRC))
OBJ_BONUS = $(patsubst %.c, $(BUILD_DIR_BONUS)/%.o, $(SRC_BONUS))

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
MLX_LIBS = $(MLX_PATH)/build/libmlx42.a -ldl -lglfw -pthread -lm
HEADERS = -I$(MLX_PATH)/include -I$(LIBFT_PATH) -Isrcs


all: $(BUILD_DIR) libmlx libft $(NAME)

bonus: $(BUILD_DIR_BONUS) libmlx libft $(NAME_BONUS)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(BUILD_DIR_BONUS):
	@mkdir -p $(BUILD_DIR_BONUS)

$(LIBFT_PATH)/libft.a:
	@$(MAKE) -C $(LIBFT_PATH)

libft: $(LIBFT_PATH)/libft.a

libmlx:
	@chmod +x $(MLX_PATH)/tools/compile_shader.sh
	@cmake -S $(MLX_PATH) -B $(MLX_PATH)/build
	@cmake --build $(MLX_PATH)/build -j4

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIBS) $(LIBFT_PATH)/libft.a $(HEADERS) -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(MLX_LIBS) $(LIBFT_PATH)/libft.a $(HEADERS) -o $(NAME_BONUS)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(BUILD_DIR_BONUS)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR) $(BUILD_DIR_BONUS)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@rm -rf $(MLX_PATH)/build

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re libmlx libft bonus
