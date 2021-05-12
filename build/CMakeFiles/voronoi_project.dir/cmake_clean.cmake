file(REMOVE_RECURSE
  "libvoronoi_project.pdb"
  "libvoronoi_project.so"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/voronoi_project.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
