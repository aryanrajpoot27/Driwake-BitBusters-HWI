const mongoose = require("mongoose")

const userSchema = new mongoose.Schema({
    name :{
        type : String,
        required : true
    },

    email :{
        type : String,
        required : true
    },
    password :{
        type : String,
        required : true
    }
}) 

const uRegister = new mongoose.model("driverRegister", userSchema);

module.exports = uRegister;