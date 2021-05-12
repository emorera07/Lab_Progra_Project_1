file(REMOVE_RECURSE
  "libVoronoi.pdb"
  "libVoronoi.so"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/Voronoi.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
