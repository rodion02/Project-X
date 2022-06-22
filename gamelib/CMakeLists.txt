add_library(game main.cpp Game.cpp Game.h State.cpp State.h GameState.cpp GameState.h Entity.cpp Entity.h CatchTests.cpp MainMenuState.cpp MainMenuState.h Button.cpp Button.h Player.cpp Player.h MovementComponent.cpp MovementComponent.h AnimationComponent.cpp AnimationComponent.h)
target_include_directories(game PUBLIC .)
target_link_libraries(game ypprpo)