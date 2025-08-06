

class Ctx {
  args: string[];

  constructor(args: string[]) {
    if (args.length === 0) {
      console.error("no args");
      process.exit(1);
    }
    
    this.args = args;
  }

  async init() {
    if (this.args[0] === "server") {
      console.log("Server mode");
      return;
    }

    console.log("Client mode");
  }
};

export default Ctx;
