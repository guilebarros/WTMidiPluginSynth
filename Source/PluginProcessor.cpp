#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
WTSynthMidiPluginAudioProcessor::WTSynthMidiPluginAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

WTSynthMidiPluginAudioProcessor::~WTSynthMidiPluginAudioProcessor()
{
}

//==============================================================================
const juce::String WTSynthMidiPluginAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool WTSynthMidiPluginAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool WTSynthMidiPluginAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool WTSynthMidiPluginAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double WTSynthMidiPluginAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int WTSynthMidiPluginAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int WTSynthMidiPluginAudioProcessor::getCurrentProgram()
{
    return 0;
}

void WTSynthMidiPluginAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String WTSynthMidiPluginAudioProcessor::getProgramName (int index)
{
    return {};
}

void WTSynthMidiPluginAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void WTSynthMidiPluginAudioProcessor::prepareToPlay (double sampleRate, int)
{
    synth.prepareToPlay(sampleRate);
}

void WTSynthMidiPluginAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool WTSynthMidiPluginAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void WTSynthMidiPluginAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    
    juce::ScopedNoDenormals noDenormals;
    
    buffer.clear();
    synth.processBlock(buffer, midiMessages);
    
}

//==============================================================================
bool WTSynthMidiPluginAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* WTSynthMidiPluginAudioProcessor::createEditor()
{
    return new WTSynthMidiPluginAudioProcessorEditor (*this);
}

//==============================================================================
void WTSynthMidiPluginAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void WTSynthMidiPluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new WTSynthMidiPluginAudioProcessor();
}
