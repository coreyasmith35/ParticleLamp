/**
 * Particle.io account information
 * Replace these with your particle.io device id and access token
 */
var deviceId = "<your-device-id-goes-here>";
var accessToken = "<your-acces-token-goes-here>";

/**
 * Particle.io cloud function
 * The Arduino sketch specifies the REST URI when it makes
 * the particle.function()
 * For example, particle.function("myFunction", myFunction)
 * would be specified as: var cloudName = "myFunction"
 * You can leave this "myFunction", or change it later
 * if you change the sketch code.
 */
var colorFunctionCloudName = "ctrlled";
var brightnessFunctionCloudName = "setBright";

/**
 * Update skillName and invocationName to match the values
 * that you specify in the Alexa Skill Kit.
 * These are only used in responses from Alexa.
 */
var skillName = "Lamp";
var invocationName = "Lamp";

/**
 * App ID for the skill
 * Update and use this if/when you publish your skill publicly.
 * It's ok to leave this undefined until then.
 */
var APP_ID = undefined; //replace with "amzn1.echo-sdk-ams.app.[your-unique-value-here]";

/**
 * The AlexaSkill prototype and helper functions
 * Particle is a child of AlexaSkill.
 */
var http = require('https');
var AlexaSkill = require('./AlexaSkill');
var Particle = function () {
  AlexaSkill.call(this, APP_ID);
};

// Extend AlexaSkill
Particle.prototype = Object.create(AlexaSkill.prototype);
Particle.prototype.constructor = Particle;

Particle.prototype.eventHandlers.onSessionStarted = function (sessionStartedRequest, session) {
  console.log(invocationName + "onSessionStarted requestId: " + sessionStartedRequest.requestId
         + ", sessionId: " + session.sessionId);
     // any initialization logic goes here
};

Particle.prototype.eventHandlers.onLaunch = function (launchRequest, session, response) {
  console.log(invocationName + " onLaunch requestId: " + launchRequest.requestId + ", sessionId: " + session.sessionId);
  var speechOutput = "Welcome to " + skillName + ", you can tell me to turn on, off or a color";
  var repromptText = "You can tell me to turn on, off or a color";
  response.ask(speechOutput, repromptText);
};

Particle.prototype.eventHandlers.onSessionEnded = function (sessionEndedRequest, session) {
  console.log(skillName + " onSessionEnded requestId: " + sessionEndedRequest.requestId
           + ", sessionId: " + session.sessionId);
  // any cleanup logic goes here
};

Particle.prototype.intentHandlers = {
  // Register custom intent handlers.
  // This simple skill only uses one, but more can be added.
  ParticleIntent: function (intent, session, response) {

 		var commandSlot = intent.slots.command;
 		var command = commandSlot ? intent.slots.command.value : "";
    
    var brightnessSlot = intent.slots.brightness;
 		var brightness = brightnessSlot ? intent.slots.brightness.value : "";

    
    
    
 		// Verify that a command was specified.
    // We can extend this to prompt the user,
    if(brightness >0){
      console.log("Brightness = " + brightness);
      
      var requestURI = "/v1/devices/" + deviceId + "/" + brightnessFunctionCloudName;
      
       var postData = "args=" + brightness;
      console.log("Post data = " + postData);

 		  makeParticleRequest(requestURI, postData, function(resp){
 		    var json = JSON.parse(resp);
 		    console.log(brightness + ": " + json.return_value);
 		    var speakText = "Ok, brightness set to " + brightness;
 		    response.tellWithCard(speakText, invocationName, "Brightness is: " + brightness );
 		  });
      
    } else if(command.length > 0){
      
      console.log("Command = " + command);
      
      var requestURI = "/v1/devices/" + deviceId + "/" + colorFunctionCloudName;

      var postData = "args=" + command;
      console.log("Post data = " + postData);

 		  makeParticleRequest(requestURI, postData, function(resp){
 		    var json = JSON.parse(resp);
 		    console.log(command + ": " + json.return_value);
 		    var speakText = "Ok, Lamp turned " + command;
 		    response.tellWithCard(speakText, invocationName, "Lamp is: " + command );
 	    });
 		} else {
 			response.tell("I don't know that command.");
 		}
  }, // ParticleIntent

  "AMAZON.HelpIntent": function (intent, session, response) {
    response.ask("You can tell " + invocationName + " to turn on, off or a color.");
  } // HelpIntent
};

// Create the handler that responds to the Alexa Request.
exports.handler = function (event, context) {
  var particleSkill = new Particle();
  particleSkill.execute(event, context);
};

function makeParticleRequest(requestURI, postData, callback){
 	var options = {
 		hostname: "api.particle.io",
 		port: 443,
 		path: requestURI,
 		method: 'POST',
 		headers: {
 			'Content-Type': 'application/x-www-form-urlencoded',
      'Authorization': 'Bearer ' + accessToken,
 			'Accept': '*.*'
 		}
 	};

 	var req = http.request(options, function(res) {
 		console.log('STATUS: ' + res.statusCode);
 		console.log('HEADERS: ' + JSON.stringify(res.headers));

 		var body = "";

 		res.setEncoding('utf8');
 		res.on('data', function (chunk) {
 			console.log('BODY: ' + chunk);
 			body += chunk;
 		});

 		res.on('end', function () {
       callback(body);
    });
 	});

 	req.on('error', function(e) {
 		console.log('problem with request: ' + e.message);
 	});

 	// write data to request body
 	req.write(postData.toString());
 	req.end();
}
