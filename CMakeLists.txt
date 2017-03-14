set(OTBAppPreprocessing_LINK_LIBS
  ${OTBPolarimetry_LIBRARIES}
  ${OTBImageManipulation_LIBRARIES}
  ${OTBApplicationEngine_LIBRARIES}
  ${OTBImageBase_LIBRARIES}
)


OTB_CREATE_APPLICATION(NAME Preprocessing
                       SOURCES Preprocessing.cxx
                       LINK_LIBRARIES ${${otb-module}_LIBRARIES})
