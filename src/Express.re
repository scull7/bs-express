let module Next = {
  type t;
};

let module Request = {
  type t;
};

let module Response = {
  type t;
  external sendFile : t => string => 'a => unit = "" [@@bs.send];
  external json: t => 'a => unit = "" [@@bs.send];
};

let module Express = {
  type t;
  external express : unit => t = "" [@@bs.module];
  external use : t => (Request.t => Response.t => Next.t => unit [@bs]) => unit = "" [@@bs.send];
  external static : path::string => (Request.t => Response.t => Next.t => unit [@bs]) = "" [@@bs.module "express"];
  external get : t => string => ('a => Response.t => unit [@bs]) => unit = "" [@@bs.send];
  external listen: t => int => unit = "" [@@bs.send];
};
