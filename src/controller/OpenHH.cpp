#include "OpenHH.hpp"

OpenHHModule::OpenHHModule( ) {
  config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
  configParam(DRUM_PARAM, 0.0, 13.0, 7.0);
  configParam(DRUM_PARAM + 1, 0.0, 13.0, 7.0);

  configParam(TUNE_PARAM, 0.2, 1.8, 1);
  configParam(TUNE_PARAM + 1, 0.2, 1.8, 1);

  numModules = 2;

  setupSamples();
}

uint8_t OpenHHModule::sampleId(uint8_t which) {
  float sample = paramValue(DRUM_PARAM + which, DRUM_CV + which, 0, 14);
  if (sample >= numSamples || sample < 0) {
    return 0;
  }

  return (uint8_t) sample;
}

void OpenHHModule::setupSamples() {
  numSamples = 14;
  char name[32];

  for (uint8_t i = 0; i < numSamples; i++) {
    sprintf(name, "openhh-%02d", i + 1);
    samples[i] = sampleManager->selectSample(name);
  }
}
