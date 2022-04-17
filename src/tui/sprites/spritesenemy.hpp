#pragma once
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
    } // namespace mysterious_forest

    namespace old_castle
    {
      extern const std::vector<std::string_view> knight;
      extern const std::vector<std::string_view> skeleton;
      extern const std::vector<std::string_view> ghost;
    } // namespace old_castle

    namespace sacred_mountains
    {
      extern const std::vector<std::string_view> angel;
      extern const std::vector<std::string_view> stone_golem;
      extern const std::vector<std::string_view> fire_spirit;
    } // namespace sacred_mountains

    namespace cave_of_time
    {
      extern const std::vector<std::string_view> greate_dragon;
    } // namespace cave_of_time
      
  } // namespace sprites_enemy

} // namespace hw
