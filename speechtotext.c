using System;
namespace Speech_To_Text_App
{
    class Program
    {
        static async Task  Main(String[] args)
        {
            await RecognizedSpeech();
            Console.WriteLine("Finished");
        }
        private static async Task RecognizeSpeech()
        {
            var configuration = SpeechConfig.FromSubscription("bf690438d8954cec8e4a53df433d6d85","eastus");
            using (var recog = new SpeechRecognizer(configuration))
            {
                Console.WriteLine("Speak something...");
                var result = await recog.RecognizeOnceAsync();
                if(result.Reason==ResultReason.RecognizedSpeech)
                {
                    Console.WriteLine(result.Text);
                }
            }
        }
    }
}