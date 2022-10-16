#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
WTSynthMidiPluginAudioProcessorEditor::WTSynthMidiPluginAudioProcessorEditor (WTSynthMidiPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{

    setSize (400, 200);
}

WTSynthMidiPluginAudioProcessorEditor::~WTSynthMidiPluginAudioProcessorEditor()
{
}

//==============================================================================
void WTSynthMidiPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    
    g.fillAll (juce::Colours::black);

    g.setColour (juce::Colours::white);
    g.setFont (25.0f);
    g.drawFittedText ("WavetableSynth", getLocalBounds(), juce::Justification::centred, 1);
}

void WTSynthMidiPluginAudioProcessorEditor::resized()
{

}
