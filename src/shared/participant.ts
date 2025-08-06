class Participant {
  id: number;
  name: string;
  public_keys: Map<string, Uint8Array>;
  contact_info: Map<string, string>;
  timezone: string;

  constructor(
    id: number,
    name: string,
    public_keys: Map<string, Uint8Array>,
    contact_info: Map<string, string>,
    timezone: string
  ) {
    this.id = id;
    this.name = name;
    this.public_keys = public_keys;
    this.contact_info = contact_info;
    this.timezone = timezone;
  }

  to_json() {
    return {
      id: this.id,
      name: this.name,
      public_keys: Object.fromEntries(
        Array.from(this.public_keys).map(
          ([key, val]) => [key, Buffer.from(val).toString("hex")]
        )
      ),
      contact_info: Object.fromEntries(this.contact_info),
      timezone: this.timezone,
    };
  }

  static from_json(json: any): Participant {
    return new Participant(
      json.id,
      json.name,
      new Map(
        Object.entries(json.public_keys).map(
          ([key, val]) => [key, Uint8Array.from(Buffer.from(val as string, "hex"))]
        )
      ),
      new Map(Object.entries(json.contact_info)),
      json.timezone
    );
  }
}

export default Participant;
