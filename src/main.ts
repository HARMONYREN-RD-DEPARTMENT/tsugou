import Participant from "./shared/participant.js";

async function main(args: string[]) {

  let user = new Participant(
    0,
    "kai",
    new Map([["tsu_verifying_public_key", Uint8Array.from([0])]]),
    new Map([["instagram", "kai"]]),
    "Asia/Tokyo");


  console.log(user.to_json());

}


main(process.argv.slice(2));
