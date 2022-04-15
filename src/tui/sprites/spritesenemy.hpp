#pragma once
#ifndef SPRITESENEMY_HPP_KU4D8LGD
#define SPRITESENEMY_HPP_KU4D8LGD
#include <vector>
#include <string_view>

namespace hw
{
  namespace sprites_enemy
  {
    namespace mysterious_forest
    {
      extern const std::vector<std::string_view> slime;
      extern const std::vector<std::string_view> fire_slime;
      extern const std::vector<std::string_view> big_slime;
      extern const std::vector<std::string_view> rare_big_slime;
      extern const std::vector<std::string_view> goblin;
    }

    namespace old_castle
    {
      extern const std::vector<std::string_view> knight;
      extern const std::vector<std::string_view> skeleton;
      extern const std::vector<std::string_view> ghost;
    }

    namespace sacred_mountains
    {
      extern const std::vector<std::string_view> angel;
      extern const std::vector<std::string_view> stone_golem;
      extern const std::vector<std::string_view> fire_spirit;
    }

    namespace cave_of_time
    {
      extern const std::vector<std::string_view> greate_dragon;
    }
  }

}

#endif /* end of include guard: SPRITESENEMY_HPP_KU4D8LGD */
